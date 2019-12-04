= ゆるふわ！？Stackdriver Logging & Monitoring

はじめまして、株式会社grasys 大川です(社内ではStackdriverおじさんと呼ばれています。)
Stackdriverをはじめて使ってみようとした際に日本語での解説が少なく取っ掛かりにくいという声を聞くことがありましたので、よくある監視構成についてゆるく執筆しました。Stackdriverの経験がない・少ない方の導入の一助になれば幸いです。

== Stackdriver のちょっと雑な説明
StackdriverはGoogle社が提供するリソース・アプリケーションのモニタリングプラットフォームです。元々StackdriverはStackdriver社が提供するサービスでしたが、2014年にGoogleが買収、以後はGoogle Cloud Platform(以下、GCP)のプロダクトStackdriver Monitoringとして提供されています。

現在はサーバの状態監視以外にもProfiler,Traceなどアプリケーションの状態管理・解析プロダクトも追加され、GCP上で提供するサービスの維持・改善を包括的に行えるプラットフォームとして進化し続けています。

=== Stackdriver関連プロダクト
2019年11月現在、GCPコンソールから選択できるStackdriver関連のプロダクトは Monitoring, 　Debug, Trace, Logging, Error Reporting, Profiler の6種類になります。

本章ではこの中から@<b>{Logging}と@<b>{Monitoring}に焦点を当て解説します。

==== Logging
GCPやAmazon Web Services(以下、AWS) からのログデータやイベントの格納、検索、分析、モニタリング、通知ができます。

==== Monitoring
Monitoringの主な特徴としてGCP、AWSをはじめとしたマルチプラットフォームの横断的な監視管理、柔軟な設定、簡易な通知設定が挙げられます。

例えばGCPのCloudSpannerやAWS RDSのようなマネージドサービスのメトリクスを取得することもできますし、OS(Linux etc.)にモニタリング用のエージェントをインストールし設定することによって、サーバが設置されている場所を問わず監視を行うことが出来ます。

※メトリクスの量によって課金額が異なってきますので、ご利用は計画的に、です。

== ゆるくログ監視と通知を試した件

それではよくある監視構成のケースとして、サーバから出力されたnginxのログをStackdriver Loggingで受け取り、statusが200,301以外だった場合にSlackへと通知する流れを解説します。

//image[image2][ログの通知フロー][scale=0.7]

=== Stackdriver Logging - ログの指標設定
最初に、LoggingからMonitoringに指標を渡す設定を行います。おおまかにはインスタンスからLoggingへログを渡すエージェント設定、Loggingに渡されたログをフィルタリングルールに従いMonitoringに渡すログベースの指標設定の2つが必要になります。

==== Logging エージェントのインストール
VMインスタンスのログを集約するためには、Stackdriver Logging エージェントをインストールする必要があります。通常、GCP内のVMインスタンスであれば特別な設定を行わずに自身のプロジェクトへログを送信することが出来ます@<fn>{log1}。またRHEL/CentOSの場合はGoogle Cloudのyumリポジトリより@<b>{google-fluentd-catch-all-config-structured}をインストールすることで、nginxをはじめとするサードパーティ製ソフトウェア向けの設定を導入できます。

本章では@<b>{google-fluentd-catch-all-config-structured}をインストールしたうえで解説を進めます。

//footnote[log1][~/etc/google-fulentd/config.d/ 以下に追記することで独自形式のログも送ることが出来ます。]

==== ログベースの指標
Stackdriver Monitoringと連携するルールの設定を行えます。今回設定する「@<b>{GCPインスタンスから出力されるnginxのログ}から@<b>{response_codeが200,301以外}をピックアップしたデータ」をモニタリングしたい場合は、GCPダッシュボード ログビューアより「高度なフィルタに変換」を選択し、下記設定のうえ「フィルタを送信」ボタンを押し決定します。

//list[sample][ルール設定 :<project_id>の部分はご自身のproject_idに置き換えてください。]{
resource.type="gce_instance" AND
logName="projects/<project_id> /logs/nginx-access" AND
jsonPayload.code!="200" OR
jsonPayload.code!="301"
//}



次に、指標エディタで指標名などを指定します。

「アイテムを追加」からフィールド名@<b>{jsonPayload.code}を指定することにより、Monitoringに送る指標にresponse_codeを含めて500系のレスポンス数と400系のレスポンス数とで通知の閾値を変えるといった運用が可能になります。

他にもフィールド名@<b>{jsonPayload.path}を指定し特定のpathを監視するなど、アイテムを使用した幅広い監視の設定が可能です。

指標の注意点として、設定された@<b>{以降}に流入したログに対してのみ有効になります。過去に遡って指標を適用することはできませんので、ご注意ください。

//image[image5][指標エディタ][scale=0.5]

@<b>{※注意}

Loggingから出力された指標をMonitoringで扱うためには、最低1回はMonitoringに指標を渡す必要があります。

指標の設定完了後は一度404など200,301以外のレスポンスが返されるリクエストを該当サーバに投げ、Stackdriver Loggingにログが格納されていることを確認してください。

=== フィルタリングの基本的な表記

ログベースの指標の設定で良く使う表記をピックアップしました。その他の詳しくはlogging ドキュメント@<b>{Advanced logs queries} @<fn>{guide}を参照してください。

//footnote[guide][https://cloud.google.com/logging/docs/view/advanced-queries]

//image[table][よく使う表記][scale=0.8]

==== ログの保存期間
　
おおよそのログは保存期間が30日までで、それ以前のログは削除されます。30日以上の期間ログを保存したい場合は「エクスポートを作成」からGCS/BigQuery等へ保存設定を行ってください。

=== Stackdriver Monitoring - 監視・通知設定

最後に、Monitoringより監視・通知の設定を行います。

==== Stackdriver Monitoring - 通知先設定
監視設定では通知先が必要なため、先にSlackチャンネルを通知先として設定します。

 1. Monitoringダッシュボードのworkspace選択より「Workspace Settings」を選択
 2. Settings一覧より「Notifications」を選択し、SLACKタブを指定
 3. Add Slack Channelを選択し、通知したいSlackのworkspaceと連携 @<fn>{slack}

//footnote[slack][退社するなどして連携を行ったSlackのアカウントが削除された場合は、Alertが発報されなくなります。Slackアカウントの運用にはご注意ください。] 

==== Alerting Policy

Stackdriver Monitoring ダッシュボードの左のメニューより Alerting > Policies を選択し、Policies一覧画面の右上にある @<b>{Add Policy} ボタンを押します。以下の項目を入力することで、通知を設定できます。

//image[table2][Alerting Policy設定内容][scale=0.5]

==== Alerting - Condition
それでは実際にConditionを設定します。例として、@<b>{200,301以外のログが1分間に30回以上出力されたら発報}を設定します。

 1. 項目@<b>{Conditions}から@<b>{Add Condition}を選択
 2. TargetのResource Typeに@<b>{GCE VM Instance}を指定
 3. Metricに @<b>{logging/user/nginx_error (logging.googleapis.com/user/nginx_error)}を指定
 4. Aggregatorに@<b>{none}を設定
 5. ConfigurationのThresholdに0.5を設定
 6. 他はデフォルトのまま
 7. save でconditionを保存

//image[image3][target設定][scale=0.5]
//image[image4][Configuration設定][scale=0.5]

注意点としては、Thresholdで判定される値は@<b>{per sec}のため、@<b>{1分間に30回以上の場合は0.5}に設定する必要があります。condition保存後にPolicyの保存を行うことで、通知設定を完了します。

==== Alert Test

ロギング設定を行ったサーバにアクセスし、404などエラーを発生させ通知を確認します。

//image[image1][通知例][scale=0.5]

=== Monitoring エージェントについて
本章ではログの監視に説明を絞ったため事後の解説となりますが、Stackdriver Monitoringエージェントについても簡単に触れます。

GCE VMインスタンスの監視項目はMonitoring API のメトリクス@<fn>{metrix}である程度の取得できますが、例えばメモリ使用率のようにメトリクスが存在しないため取得することが出来ない項目があります。そのような場合、Monitoringエージェントを導入することでAPIで取得できない監視項目を補うことが出来ます。また、サーバプロセス(例: nginx)の稼働状況を監視したい場合も、エージェントをインストールすることにより監視が可能になります。

//footnote[metrix][https://cloud.google.com/monitoring/api/metrics_gcp#gcp-compute]

エージェントは@<b>{collectd}@<fn>{collectd}にGCP連携のための設定を追加したものが使用されています。多くのミドルウェアは事前定義されているためそのままメトリクスを収集できますが、自社製サーバプログラムなどを監視したい場合などは別途カスタムメトリクスを作成する必要があります。

//footnote[collectd][https://collectd.org/]

== おわりに

駆け足となりますが、Stackdriverによるログの監視の入り口についてふんわり説明しました。ログの監視は奥深く、ステータスだけではなくpath単位でのエラーの出現頻度を割り出したり、インスタンスだけではなくLoadbalancerをはじめとするマネージドサービスのログを元に応用することが出来ます。

また、Stackdriverには他にも様々なプロダクトがありますので、障害監視をはじめアプリケーションのレスポンス改善など、開発・運用するサービスの品質向上にお役立ていただけますと幸いです。

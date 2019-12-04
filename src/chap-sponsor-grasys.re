=[nodisp] ゆるふわ！？Stackdriver Logging & Monitoring

はじめまして、株式会社grasys 大川です(社内ではStackdriverおじさんと呼ばれています。)
Stackdriverをはじめて使ってみようとした際に日本語での解説が少なく取っ掛かりにくいという声を聞くことがありましたので、よくある監視構成についてゆるく執筆しました。Stackdriverの経験がない・少ない方の導入の一助になれば幸いです。

== Stackdriver のちょっと雑な説明
StackdriverはGoogle社が提供するリソース・アプリケーションのモニタリングプラットフォームです。元々StackdriverはStackdriver社が提供するサービスでしたが、2014年にGoogleが買収、以後はGoogle Cloud Platform(以下、GCP)のプロダクトStackdriver Monitoringとして提供されています。

現在はサーバの状態監視以外にもProfiler,Traceなどアプリケーションの状態管理・解析プロダクトも追加され、GCP上で提供するサービスの維持・改善を包括的に行えるプラットフォームとして進化し続けています。

=== Stackdriver関連プロダクト
2019年11月現在、GCPコンソールから選択できるStackdriver関連のプロダクトは Monitoring, 　Debug, Trace, Logging, Error Reporting, Profiler の6種類になります。

本章ではこの中からLoggingとMonitoringに焦点を当て解説します。

==== Logging
GCPやAmazon Web Services(以下、AWS) からのログデータやイベントの格納、検索、分析、モニタリング、通知ができます。

==== Monitoring
Monitoringの主な特徴としてGCP、AWSをはじめとしたマルチプラットフォームの横断的な監視管理、柔軟な設定、簡易な通知設定が挙げられます。

例えばGCPのCloudSpannerやAWS RDSのようなマネージドサービスのメトリクスを取得することもできますし、OS(Linux etc.)にモニタリング用のエージェントをインストールし設定することによって、サーバが設置されている場所を問わず監視を行うことが出来ます。

※メトリクスの量によって課金額が異なってきますので、ご利用は計画的に、です。

== ゆるくログ監視と通知を試した件

それではよくある監視構成のケースとして、サーバから出力されたnginxのログをStackdriver Loggingで受け取り、statusが200,301以外だった場合にSlackへと通知する流れを解説します。

//image[image2][ログの通知フロー]

=== Stackdriver Logging - ログの指標設定
最初に、LoggingからMonitoringに指標を渡す設定を行います。おおまかにはインスタンスからLoggingへログを渡すエージェント設定、Loggingに渡されたログをフィルタリングルールに従いMonitoringに渡すログベースの指標設定の2つが必要になります。

==== Logging エージェントのインストール
VMインスタンスのログを集約するためには、Stackdriver Logging エージェントをインストールする必要があります。通常、GCP内のVMインスタンスであれば特別な設定を行わずに自身のプロジェクトへログを送信することが出来ます@<fn>{log1}。またRHEL/CentOSの場合はGoogle Cloudのyumリポジトリより google-fluentd-catch-all-config-structured をインストールすることで、nginxをはじめとするサードパーティ製ソフトウェア向けの設定を導入できます。

本章では google-fluentd-catch-all-config-structured をインストールしたうえで解説を進めます。

//footnote[log1][~/etc/google-fulentd/config.d/ 以下に追記することで独自形式のログも送ることが出来ます。]

==== ログベースの指標
Stackdriver Monitoringと連携するルールの設定を行えます。今回設定する「GCPインスタンスから出力されるnginxのログからresponse_codeが200,301以外をピックアップしたデータ」をモニタリングしたい場合は、GCPダッシュボード ログビューアより「高度なフィルタに変換」を選択し、下記設定のうえ「フィルタを送信」ボタンを押し決定します。

//list[sample][ルール設定]{
resource.type="gce_instance" AND
logName="projects/<project_id> /logs/nginx-access" AND
jsonPayload.code!="200" OR
jsonPayload.code!="301"
}

次に、指標エディタで指標名などを指定します。

「アイテムを追加」からフィールド名 jsonPayload.code を指定することにより、Monitoringに送る指標にresponse_codeを含めて500系のレスポンス数と400系のレスポンス数とで通知の閾値を変えるといった運用が可能になります。

他にもフィールド名jsonPayload.pathを指定し特定のpathを監視するなど、アイテムを使用した幅広い監視の設定が可能です。

指標の注意点として、設定された以降に流入したログに対してのみ有効になります。過去に遡って指標を適用することはできませんので、ご注意ください。

//image[image5][指標エディタ]

@<b>{※注意}

Loggingから出力された指標をMonitoringで扱うためには、最低1回はMonitoringに指標を渡す必要があります。

指標の設定完了後は一度404など200,301以外のレスポンスが返されるリクエストを該当サーバに投げ、Stackdriver Loggingにログが格納されていることを確認してください。

=== フィルタリングの基本的な表記
　ログベースの指標の設定で良く使う表記をピックアップしました。その他の詳しくはlogging
ドキュメントAdvanced logs queries を参照してください。

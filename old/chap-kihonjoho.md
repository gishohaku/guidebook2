# 情報処理技術者試験の基本情報技術者試験における、試験範囲「試験要綱」Ver. 4.2～4.4改定について(2019秋試験対応版)

## ご挨拶

技術書同人誌博覧会にご参加の皆様、はじめまして。ふーれむ(Twitter:@ditflame)と申します。
先日、「技術書を執筆しよう！初心者向け勉強会」[^connpass]　に参加をさせて頂いた折、お声掛けいただき、今回執筆させて頂くことになりました。普段は大阪で社内ＳＥをしております。

今回は、情報処理技術者試験の基本情報技術者試験における、試験範囲「試験要綱」Ver.4.2からVer.4.4までの改定について、2019年秋試験終了時点での現在の情報をお伝えできればと思います。

[^connpass]: https://gishohaku.connpass.com/

## はじめに

情報処理技術者試験は、「情報処理の促進に関する法律」[^2]で定められた、情報処理に関する国家試験です。
今回はその試験の中の1区分である「基本情報技術者試験」[^3]について、現段階で得られる最新の情報を記載します。
なお、情報処理技術者試験は年２回（春と秋）に行われており、本記事でも「2019年秋」などの表記で記載しています。

[^2]: https://elaws.e-gov.go.jp/search/elawsSearch/elaws_search/lsg0500/detail?lawId=345AC0000000090

[^3]: https://www.jitec.ipa.go.jp/1_11seido/fe.html

情報処理技術者試験は何年か一度、試験範囲の見直しが入ることがあるのですが、2019年1月に試験を主催するIPAから、新たな試験要綱に関するプレスリリース[^4]が発表されました。
これによると、基本情報技術者試験は2019年春まで、2019年秋、2020年春からの試験それぞれで、少しずつ試験内容が変わるということになります。

[^4]: https://www.ipa.go.jp/about/press/20190124.html

更に先日、新技術への対応とセキュリティ強化のための新たな試験要綱に関するプレスリリース[^5]が発表されました。これによると、基本情報技術者試験に関しては、次回(2020年春試験)より午前試験におけるセキュリティ分野の設問が重点範囲に指定されました。

[^5]:https://www.jitec.ipa.go.jp/1_00topic/topic_20191105.html

## 基本情報技術者試験の時期と試験要綱の対応について

まず、全体の変化を図示すると次のようになります。

|　|2019春まで|2019秋|2020春から|
|--|--|--|--|
|午前試験|現行と同じ|**新要綱(V4.2)での出題**|**新要綱(V4.4)での出題**|
|午後試験|現行と同じ|現行と同じ|**新要綱(V4.4)での出題**|

## 午前試験の新基準(V4.2:2019秋以降)について

先のプレスリリース[^4]から要点を引用します。

>(3）午前試験での数学に関する出題比率の見直し(適用時期:2019年秋期試験から）
>理数能力を重視し、線形代数、確率・統計等、数学に関する出題比率を向上

この要綱が適用された第１回目の試験(2019年秋試験)はすでに終了しており、また出題された問題に関してはHP上で公表されています。
まず、これを分析したものを以下に示します。なお分類に関しては、共通キャリア・スキルフレームワーク[^6]を基準として分類を行いました。(分類に関しては筆者の独断で妥当性のありそうな分類に落とし込んでいます。）

[^6]: https://www.ipa.go.jp/jinzai/itss/ccsf/download.html

### 午前試験の実際の変更点について(大枠）

まず結論として、過去試験(2016年秋～2019年春)と比べて、全体の出題数(80問)、及びテクノロジ系、マネジメント系、ストラテジ系での出題比率に変更はありませんでした。

|分類|出題数|比率|
|--|--|--|
|テクノロジ系|50問|62.5%|
|マネジメント系|10問|12.5%|
|ストラテジ系|20問|25%|

### 午前試験の実際の変更点について(テクノロジ系）

続いて、テクノロジ系の中での変化でいうと、以下のような形になりました。

|分類|出題数|比率|備考|
|--|--|--|--|
|基礎理論|8問→11問|10%→13.8%|出題数増(応用数学を含む分野のため)|
|コンピュータシステム|15問→11問|18.8%→13.8%|出題数減|
|技術要素|22問→22問|27.5%→27.5%|出題数変わらず|
|開発技術|5問→6問|6.3%→7.5%|出題数微増|


### 午前試験の次回試験(V4.4:2020年春)以降での変更点(予想)

筆者の推測としては、大枠の出題比率は変更されず、テクノロジ系の出題比率が調整され、結果としてセキュリティに関する出題数が増加する　といった形での調整が入るのだろうと予想しています。

#### [column] 午前試験のような多岐選択式試験をクリアするためのポイント

結局のところ、用語と概念をどれだけ覚えているかが午後の解答力にも効いてきます。まず午前をしっかり解けるようになるのが大事な気がしています。

予め準備しておくものとしては、

* 教科書的なものを1冊
* 過去問を印刷できる環境
* 朱書き用のペン
* ルーズリーフ
* テープのリ(コクヨのドットライナーがお勧め。)
* はさみ

があると良いです。

以下、対応手順です。

1. 初回受験者は、まず適当な厚さの本(基本論点が乗っている教科書的なもの)を1～2回通読。
2. IPAのサイトに過去問[^kakomon]があるので、過去3年分(3年×春、秋で6回分になるはず)を**片面印刷**で印刷。
3. 過去問を解きましょう。前々回の試験問題から過去に遡って解いていきます。(前回と同一の問題は、過去に出たことが無い事から、前回過去問は知識の抜け漏れが無いかのチェックのため、最後に時間があれば解くぐらいの扱いで良いです。ただし、**2020年春試験を受験する人のみ**2019年秋試験の試験問題は**出題比率を見るため**、一度解いておいたほうが寄より良いと思います。)
4. 間違えた問題をルーズリーフに切り貼りして、ミスノートを作成しましょう。(解答導出手順や用語の説明は朱書きするもよし、過去問題集の正答がどこかで手に入る場合はそれも印刷ないしコピーして貼るのも良いでしょう。)

あとは、4.で作成したミスノートを集中的にこなせば、7割ぐらいはコンスタントに得点できるようになっているかと思います。

なお、あまり情報処理技術者試験の受験経験が無い方には認知されていないポイントなのですが、午前の多岐選択試験で過去問から再出題される問題は、**問題と選択肢まですべて一緒の形で、過去問からそっくりそのままの形で**再出題されます。

[^kakomon]: https://www.jitec.ipa.go.jp/1_04hanni_sukiru/_index_mondai.html
(※注１:**そっくりそのまま出てこない場合はパラメータなどが違う新問**です。新問の出題率は試験の時期によっても差がありますが、今までの感覚でいうと多くて2～3割ぐらいです。なお、新問 ≒ 新出題論点となっていることが多いので、本試験の午前で新問に出くわした場合は昼休憩のタイミングで用語をググってチェックぐらいはしたほうがいいこともあります。実際に午後で同一論点の出題が出たりします(私が受けた時のセマネでは本当に出て、助かったということもあったので…。））

(※注２:高度情報の午前試験ですら同様の運用のため、この出題方針にもし変更があるならば、まずは高度情報試験から変更が入ると思われます。）

#### [/column]

## 午後試験の新基準(2020春以降)について

大問の構成は以下のように変わると先のプレスリリース[^4]には記載されています。

* 現行(2019年秋試験まで)→新基準(2020年春試験から)

|問番号|必須選択|選択数|配点|
|--|--|--|--|
|問1:情報セキュリティ|〇 |1 |12→**20**|
|問2～7→問2～5|　|4→**2**|12→**15**|
|問8→問6:データ構造及びアルゴリズム|〇 |1 |20→**25**|
|問9～13→問7～11:ソフトウェア開発(プログラム言語)|　|1 |20→**25**|

※現行:問2～7は以下の設問

* ハードウェア or ソフトウェア or データベース or ネットワーク　から3問
* ソフトウェア設計　から1問
* プロジェクトマネジメント or サービスマネジメント　から1問
* システム戦略 or 経営戦略・企業と法務　から1問

※新基準:問2～5は以下の設問

* ハードウェア or ソフトウェア or データベース or ネットワーク or ソフトウェア設計　から3問
* プロジェクトマネジメント or サービスマネジメント or システム戦略 or 経営戦略・企業と法務　から1問

これを受け、どの部分が試験として変わるかを以下にまとめます。


### 変更点１:大問のトータルでの選択数が減少し、配点が増えた

あらゆる試験における一般論として、そもそも問題の出題に割り振れる**ページ数は、一般的には問題の配点に正比例**します。問題の配点が増えるということは、出題に使えるページ数が当然増えるので、結果として問いの内容が深くなる　ないし、広くなる方向になるでしょう。

### 変更点２:情報セキュリティの配点が大幅に増えた

昨今の情報セキュリティ人材が不足している状況を踏まえて、配点を増やしているのだろうなと考えられます。これに伴い、情報セキュリティマネジメント試験(セマネ)の受験者は少し有利になるでしょう。

また、今後の試験の受験パスを考えたときに**情報セキュリティ分野に関しては**高度試験も(歴史的な経緯から)春秋両方で唯一開催されており、**得意分野にしておく**のが望ましかったのですが、更に、最近のプレスリリース[^5]で、高度情報試験のほぼ全般に影響のある、試験範囲の改定が発表されました。

この改定では高度情報試験の各種試験に対し、午前試験でのセキュリティ分野の出題レベルがかなりの高度試験で強化（３→４レベルの出題に変更）され、更に重点範囲に指定されました。このため、情報処理技術者試験を他の分野でも受ける予定があるのであれば、セキュリティは重点的に抑えておくのが望ましいです。

## 新基準における午後試験対策について

以下、個人的な主観に基づいた対策案を書いておきます。受験者の方は参考にしてみてください。

### 問1(必須) 情報セキュリティ

必須なので頑張りましょう。なお昨今の状況を見るに、応用情報でも情報セキュリティが必須、高度でも通年で受験可能なのは情報処理安全確保支援士試験のみ、更に各種スペシャリスト試験でもセキュリティに絡めた設問が重点範囲に指定されたことを考えると、得意分野にしておくのが後々の受験パスを考えても良いかと思います。セマネを受けるのも**今まで以上に**良いでしょう。

### 問6(必須) データ構造及びアルゴリズム

必須なので頑張りましょう。どんな言語でも良い(基本の午後に出てくる言語に絞って、無理に頑張る必要は無い)のですが、手を動かしてループ、データ構造(木やハッシュ)、探索、ソーティングアルゴリズムに関してスクラッチで書いてみると、理解が深まっていくと思います。

### 問2～問5(2問選択)

* ハードウェア

技術変化の少ない試験領域です。(計算機の基礎なので変わりようが無いため)
論理回路は独特なので覚えるコストが少し高いのですが、エンベデッド系の基礎になるので知っておいたほうが良いと個人的には考えています。ただ、人によっては要らないでしょうね…

* ソフトウェア

ＯＳなど基本ソフトウェアの話が中心になります
基本的には知っているか知ってないかで選択を決めることになる気がします。ただしこういった知識はシステムを組む上で有用ですし、学んでおいて損は無いです。

* データベース

比較的技術変化の少ない試験領域です。(データベースにおける論理的な整合性を支える理論は変わりようが無いため)

また、学生さんなどは普段から触ってないと少ししんどいかもしれないです。

* ネットワーク

プロトコルは比較的技術変化が少ない(物理層のI/Fは3～4年経つと1世代変わったりするけども)ですし、今の情報処理技術者試験は基本的にOSI参照モデルのデータリンク層以上を問う傾向が強い気がしています。

* ソフトウェア設計

システム設計的な観点での設問になります。技術変化は少ないのですが、対象とする物理的な業務に合わせたシステムの問いが来るので過去問をやっておくと一番幸せになれる分野だと思います。

* プロジェクトマネジメント or サービスマネジメント

マネジメント系の問題は基本的には文章題です。読んで理解できれば解ける公算が大きいです。ＩＴエンジニアで開発職なら関わることも多い分野なので、知っておくに越したことは無いのですが、判断に困るなら避けるのも手です。

* システム戦略/経営戦略 or 企業と法務

ストラテジ系の問題も基本的には文章題ですが、たまにお金の話とか法律の話が出てくるので普段関わりが無いと辛い気がします。

### 問7～問11(1問選択) ソフトウェア開発(プログラム言語)

C，Python，Java，アセンブラ言語(CASLⅡ)，表計算ソフトの5種から選択します。

とりあえず、はっきりいえるのはCや Python、Javaが超得意でずっとコード書いてるマン以外は**無理に多少知っているからといってそういう言語を選ばないほうが幸せ**かもしれないです。

理由としては、各言語に対しての割り当てられる試験冊子のページ数は当然決まっているだろうと推測されますし(今までの試験で1言語6ページぐらいだったので、増えて8ページぐらいと予想…）、**同一の記述量であれば記述性の低い言語のほうが当然ロジックは簡単**になることから、問いも単純なものになると考えられます。

あと、**アセンブラと表計算は試験問題集巻末にリファレンスが絶対に付く**ので解答導出手順さえわかっており、時間を割ければ確実に点が取れるという点が非常に重要な気がします。

(※注:表計算は標準的な規格が無い事から、アセンブラはアーキテクチャ差異による有利不利が出ないよう、独自にCASL2を定義している事から、それぞれ試験問題の巻末にリファレンスが付いている、という経緯だと伺った事があるのですが、Pythonに関してはリファレンスが試験問題に付かないことがすでに公表されています。[^7])

[^7]: https://www.jitec.ipa.go.jp/1_13download/shiken_yougo_ver4_2.pdf

よって合格を単純に目指すのであれば、言語選択のお勧めは **表計算ソフト** か **アセンブラ言語(CASLⅡ)** になります。

ただし、配点が20点から25点に増えている関係で出題ページ数も２割ぐらい増えるのでは？と予測しており、結果、問われるロジックの解析能力や出題される問題数が増えると、人によっては結構つらくなるかもしれません。

※ページ数が線形的に増えたと仮定した場合、ソースコードの長さに対しての複雑度は一般則として指数的に増える傾向があり、この性質が出題にモロに効いてくると辛いですね。

そういう意味でも、仮にロジックが複雑になったとしても程度が知れている表計算かアセンブラがやはり比較的楽に解けるではと考えていますが、どうなるでしょうか。

## おわりに

私が初めて情報処理技術者試験を受けたのは、かれこれ20年前(1999年秋試験)の初級システムアドミニストレータ試験からでして、気づいたら20年経っていたのか…　などと思い返しながら書かせて頂きました。

試験制度の変遷なども長い間見てきているのですが、やはり試験改定を含めた上での試験対策はなかなか対策が悩ましいですね。
あと、書いている途中にプレスが出てしまい、追いつくのが大変でしたが（提出期限超過してすみません… orz）、この記事が皆さんのキャリアアップの一助になれば幸いです。

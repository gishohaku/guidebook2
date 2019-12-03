# 自然言語のシンタクスハイライト　次世代の速読技術

## ご挨拶

技術書同人誌博覧会ご参加の皆様、はじめましてpolymonyRksと申します。普段はメーカーで画像処理関連のソフトウェア開発をしております。

数カ月前に、運営様開催の「技術書を執筆しよう！初心者向け勉強会」[^connpass]に参加させていただきました。
それをきっかけに、本公式ガイドブックに寄稿する機会をいただけました。運営様ありがとうございました。  

さて、私は趣味でプログラミング言語Haskellで電子文書リーダーを開発しています（https://www.polymony.net）。
文章を文法に従い着色（シンタクスハイライト）することで速読と精読を可能とするものです。  

今回は、その技術についてご紹介します（なお、以下の各強調(ボールド体、イタリック体など)は、本当は「着色している」と想定して読んでください）。

[^connpass]: https://gishohaku.connpass.com/

## 技術紹介
速読、精読の対象として、専門書や技術書を想定しています。一部の速読エリートを除けば、これらの本を速読するのは難しいと見ています。

そういう速読術を極めていない人[^1]でも、これらの本を読みやすくする方法を発見したのでご紹介します。

### プログラムのシンタクスハイライト

着色により文書の視認性を著しく向上させている領域があります。プログラムのソースコードへの着色（シンタクスハイライト）です。そこからプログラマが受ける恩恵は計り知れないです。
身近なところでは、ハイパーリンクの表示（地の文との区別、履歴有無による色違い）もありますね。以上がプログラムの世界での成功例です。  

次に普通の文章（自然言語）についてですが、筆者が自身の赴くがままに着色を施した場合、
一歩間違えると酷いことになります（インターネット黎明期、サイト、特徴とぐぐってみてください。当時は実験的な時期でした）。  
しかし、以下の三点を心がければ自然言語でも着色の恩恵を受けられる事が確認できました。すなわち、  

1. 名詞句単位で、
2. 読者が着色モードを把握し、
3. 読者自らアドホックに着色する。

というものです。以下詳細を見ていきます。  

### 名詞句単位の着色

具体例として、まずは以下の２つの文章を比較してみてください。  

#### [column] ケースA  

技書博は **技術書を頒布される方のみサークル出展いただけます** 。  

出展者は **各自の良識の範囲で「技術」を定義し** 、自らがもつ技術を共有する場としてご利用ください。  

私たち運営事務局は、 **エンジニアによるアウトプットを推進し** 、 **知識の共有によってより良いエンジニアコミュニティを築き** 、また参加される皆さんが **共に成長することを望んでいます** 。  

#### [/column] 

#### [column] ケースB  

技書博は **「技術書を頒布される方」** のみサークル出展いただけます。  

出展者は **各自の良識の範囲** で **「技術」** を定義し、自らがもつ技術を共有する場としてご利用ください。  

私たち運営事務局は、 **エンジニア** による **アウトプット** を推進し、 **知識の共有** によって **より良いエンジニアコミュニティ** を築き、また参加される皆さんが **共に成長すること** を望んでいます。  

#### [/column] 


（ケースB)のほうがグッと読みやすくなっていますね（筆者は手間ですが）。さらに下の拙い英文も見てください。  

#### [column] ケースC  
We make some toy programs in Haskell. The current one is a viewer for PDF Documents, characterized by ad hoc coloring of noun phrases for fast and accurate reading. There is another delimiter other than space.  

#### [/column] 

#### [column] ケースD  
We make **some toy programs** in **Haskell**. **The current one** is **a viewer** for **PDF Documents**, characterized by **ad hoc coloring** of **noun phrases** for **fast and accurate reading**. There is **another delimiter** other than **space**.  
#### [/column] 

英語が読める人は(ケースC)が（ケースD）のように見えているはずです。英語が苦手な人は、こういう単位を意識したほうが良いです。さて、これらは強調箇所はいずれも「名詞句」に相当しています。  

#### 名詞句の定義

「名詞句」とは「指示代名詞」により置き換え可能な単位を指します。日本語なら「それ」、英語なら“it“にあたります。上の例文も確かにそうなっています。  

この着色方針は何らかの文法に従っている、というのがプログラミング言語と似ています。この事実をもってこの技術を自然言語のシンタクスハイライトと呼んでいます。  

### 着色モードの把握

次に、名詞句単位という縛りに加えて、読者側が着色モード[^2]を把握していることも重要です。まずは着色モードの一例として下の文章(ケースE)を参照ください。  

#### 着色モード（一例としての日付と料金）


#### [column] ケースE  

サークル参加は **有料** 。「通常スペース」 **出展料：5000円** 、.. 「ゆったりスペース」 **出展料：8000円** の２種類あり、..申込期限は[u:9月22日] 

#### [/column] 

いかがですか？再度述べますが、実際には色を使い分けていると想像してください。
なお、名詞句単位でやらないと以下の(ケースF)のようにキメラ状態になってしまいます。

#### [column] ケースF  

サークル参加は 有**料** 。「通常スペース」 出展**料**： [i:5000] **円** 、.. 「ゆったりスペース」出展**料** ： [i:8000] **円** の [i:2] 種類あり、..申込期限は  [i:11]  [u:月]  [i:22] [u:日]

#### [/column] 

これは、完全一致で「円」、「料」、は**ボールド**、数字は [i:イタリック] 、「月」「日」は [u:アンダーバー] になるよう指定した場合です。  

キメラ状態を回避するために、名詞句全体を完全一致で着色しようとしても指定語を網羅しきれません。上の事例であれば、名詞句単位の場合は、部分一致指定で「料」、「円」、「月」、「日」の４つの指定で足ります。
一方で完全一致の場合、「有料」、「出展料」、「５０００円」、「８０００円」、「１１月」、「２２日」と6個も指定する必要があります。
数値に関しては網羅できそうにないです。

また、仮に網羅できたとしても指定する名詞句が多くなるため、計算速度が著しく低下してしまいます。  

名詞句単位で予め文章を分割しておいて、かつ部分一致で、少ない設定で包括的に着色するのが大事です（技術が進めば部分一致以外の包括指定もできそうですね）。


#### モード把握の必要性
上のモードで、カテゴリと色の対応（日付系は何色、料金系は何色）を事前に知っておくのがベストですが、
事前知識がなくても趣旨は理解できたと思います。では、次の例はいかがでしょうか？(ケースG)と (ケースH)で、どういう意図で着色しているか分かりますか？


#### [column] ケースG

[u:速読]、[u:精読]の対象として、**専門書**や**技術書**を想定しています。一部の [u:速読エリート] を除けば、これらの本を[u:速読]するのは難しいと見ています。

[u:そういう速読術]を極めていない人でも、これらの本を[u:読み]やすくする方法を発見したので[i:ご紹介]します。

#### [/column] 　  

#### [column] ケースH  

[i:速読]、**精読**の[u:対象]として、[i:専門書]や**技術書**を[u:想定]しています。[i:一部]の**速読エリート**を除けば、これらの[u:本]を[i:速読]するのは難しいと見ています。

**そういう速読術**を極めていない[u:人]でも、これらの[i:本]を**読み**やすくする[u:方法]を[i:発見]したので**ご紹介**します。

#### [/column] 

（ケースG）はScoutモードです。ページ内に出現する各単語の語根についてヒストグラムを取り、その上位6位までをサイクリックに着色しています。名詞句単位で、という縛り付きです。これはこの記事の冒頭にある文章ですが、１ページ目には「書」「技術」「読」「着色」「シンタクスハイライト」「紹介」の順に多く出てきているようです。よく出てくる単語は重要だから着色しておこうという趣旨です。この文章だけを見ていても、この趣旨はわからないと思います。  

これは非常に重要なモードです。文書を読む前から情報を先取りできます（なのでScoutモードと呼んでいます）。ただしそういうモードにあると分かっていないと、逆に混乱してしまいます。  

（ケースH）は、Grammaticaモードです。名詞句の出現ごとにサイクリックに三色で着色しています。これは、構文解析がうまくいっているかを確認するモードです。
これを見ると「想定しています」、「速読する」、「読みやすく」、「発見した」、「ご紹介します」あたりをどう扱うかを再検討したほうが良さそうですね。  

これも開発者の観点では非常に重要なモードです。実は英文のほうが目に映える感じになりますが、ここでは割愛します。これも意図がわからないとアートとしての理解だけで止まってしまいます。  

　

このように、同じ文章であってもモードが異なると着色パターンが異なってきます。  

筆者が何らかの意図で親切に着色してくれていることがあります。しかし、その意図を読者がすぐに理解できないとノイズになりかねないです。
複数の色が使い分けられている場合は特にそうです。


### アドホックな着色

最後に、読者自身が読書中にアドホックに着色するのも重要です。アドホックとは、状況に応じてその都度という意味です。  
ここでは着色の過程をご説明できないので残念ですが要点を述べますと、自然言語のシンタクスハイライトは  
+ **筆者(プログラマ)**が**執筆時（コンパイル時）**に**スタティックに用意するもの**ではなく、  
+ **読者（ユーザー）**が**読書時（ランタイム時）**に**ダイナミックに主体的に行うもの**である、ということです[^3]。  

モードの設定は作者ではなく読者がする、ということです。これは実際にソフトを使ってみないとわからない体験です。  

私のHPに動画や体験版を用意していますので、興味のある方は参照してみてください。この記事もアップロードしておきます。是非ご自身で着色して読んでみてください。   

## あとがき


### 技術に対する個人的思い


最後まで読んでいただきありがとうございました。  

私は以前は完全なペーパー主義者でした。が、上記技術を使った電子書籍リーダを開発し始めてからは、電子版（pdf版)も購入するようになりました[^4]。
本当に読むのが楽です。自分の専門領域は当然楽ですが、普段読もうとも思わない本（哲学書とか医学書とか法律書とか）も楽勝な感があります。
これは自分だけに留めずに普及させるべき技術と確信しています。  

ただし、今はサンデープログラマのおもちゃレベルです。普及させるノウハウもなく、使う技術も自分だけでは到底カバーしきれていません。一緒に活動していただける人募集中です。
ご興味ある方は私のHP（関数型玩具製作所：https://www.polymony.net）を見て連絡頂けると幸いです。  

一応この技術関連で特許出願もしています。審査する人の理解のために、提出した文書自体に技術を適用したものを具体例としています。
再帰的なやり方でHaskellみたいな関数型プログラミングっぽいと一人で勝手に満足しています（笑）。
ソフトウェア界隈だと特許を書くのはどうなんですかね？という考え方もありますが、
弱小の個人や組織が持続可能な開発を行ったり、対価をいただいたりするには必要なことと自分は考えています。
大きい企業（Google社とかAmazon社）もなんだかんだソフトウェア特許を出してます。
ただし、特許だけとっておいて自分は開発せずに、誰かが製品化したものを訴えてお金を得るというのは、
エンジニアとしてどうかな？、と思っています。自分が絡む形で完成させたいです。  

### 次回予告

次回はこの電子書籍リーダの自作方法についての同人誌（言語はHaskell）を書く予定です [^5] [^6]。
Haskell界ではGUIの例があまりないので、貢献できると思ってます。
今は古典的なGtk2hsを使っていますが、Elm Architectureを参考にしたというGtk-Declarativeをネタにしたいです。
自然言語のシンタクスハイライト技術はparsingに強いHaskellや、論理を扱えるAgdaでの開発が有利とみているので、これら言語の普及の一助になりたいです。

その際もよろしくお願いします。

-----------------------------------------------------------------------------------------

[^1]: 自分も速読術についてはよく分かっていません。極めれば専門外の専門書も読めるとの声がありますが懐疑的です。

[^2]: 文脈に対応した着色をEmacs（プログラミングエディタ）に倣い「モード」と呼んでいます。Haskellモードとかmarkdownモードとかそういうのです。文法に従い着色とかエラーチェックしてくれます。  

[^3]: 技術誌的に最後に良いこと言ったと自負していますが、さっそく自己矛盾してる感があります。  

[^4]: ペーパー or 電子の選択ではなく、AR技術で紙の文書を着色して読む、というのがひとつの完成形と見ています。  

[^5]: 先ほどの特許云々はなんだという感じですが、個人が個人で自分で作る分には特許とか問題にならないですし、仮に問題になったとしても権利主張するつもりは全くないです（ここで明言します）。  

[^6]: プログラミング教育の題材としても、学習者のモチベーションの点で筋が良いかなと思っています。

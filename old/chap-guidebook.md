# ガイドブック編集長のヤクザなお仕事

技書博公式ガイドブック編集担当、親方@oyakata2438です。

本章では、ガイドブック編集の裏話をお届けしたいと思います。様々な原稿形式があり、それを最終的に入稿可能なpdfにまとめ上げる必要があります。たいてい原稿は締め切りギリギリになります。入稿期限が迫っている中でどう効率的に入稿に向けた原稿の編集作業をやっていくかという点について書いてみたいと思います。なお本章ではいわゆる文章校正については触れません。入稿可能な完成原稿を作るための作業というフェイズにあることをご承知おきください。またこのテクニックは、基本的には合同誌などの編集長向けの記事です。ゲスト原稿がある時などに役に立つ可能性がありますが、一人で執筆する場合にはあまり役に立たないかもしれません。

## Step0 原稿を集める
原稿を集めます。寄稿者、執筆者を鼓舞し、原稿を作ってもらいます。著者は、締め切りを設定しないと書き始めません。与えられた締め切りを少し過ぎた頃が一番筆が乗ります。したがって、表の締め切りを、本当の締め切りの前に設定します。間違っても、本当の締め切りを著者に伝えてはいけません。

## Step1 pdfに変換する
集まった原稿はすべていったんPDFに変換してしまいます。変換そのものの手順ではなく、変換するにあたって確認した方がよいところを中心に述べます。

技所博公式ガイドブックは、

* Google Doc
* Google Slide
* Re:VIEW
* Adobe Illustrator
* (何かで作った)pdf

といった風に、さまざまな形式の原稿が存在します。

### Google Slide(諸注意・サークルカット一覧など)

技書博ガイドブックでは、主催挨拶や諸注意、サークルカットの一覧、会場配置図などをGoogleSlideで作っています。

* 箇条書きや画像の貼り込み、注意事項を矢印で入れたりなど、柔軟に操作できることが必要
* 各担当者が作成し、複数人でチェックし、間違いを減らす必要
* リモート編集・同時編集が可能である

Google Slideで作るメリットは上記の理由になります。なお、サークルアピール(B5半分相当)もGoogleSlideで作っていますが、こちらは後述します。

Google Slideのメニューからは、Download as PDFとDownload as PPTX(Docx)のメニューがありますが、直接pdfとしてダウンロードするのではなく、一旦PPTXでダウンロードして、オフラインで確認してからローカルでpdf化することをお勧めします。画像や文字のずれ、はみ出し等がどうしても発生する可能性があります。文字のずれは、オンラインで確認したのち、ローカルにダウンロードしたpptxで確認します。改行がおかしいところ、画像がずれたり飛んだりしていないか、変な空白がないか、といった観点で全ページチェックするようにしましょう。

編集長はWindowsユーザーです。Windowsユーザーであれば、比較的標準的にWordやPowerPointをお持ちかもしれませんが、Macユーザーでは所有している可能性は一気に下がるでしょう。Keynote等で可能な範囲で編集するか、オンラインで編集し、PDFでダウンロードしてずれがないか確認するなど、十分注意します。

また、この段階で目次の項目だけは作っておきましょう。案外忘れがちなのが、章扉やまえがきあとがきなどです。結合後に目次の行数が増えて２ページになったりするとノンブルづけに苦労します。ページ数はPDFビューアから確認できますので、合体後に手で拾って入れます。一旦もくじのページ数を確定するために、目次で抽出したい項目はすべて、忘れないように現段階で入れておきます。

### Re:VIEW原稿
技術記事(サポーター企業様の技術記事、スタッフの技術記事)はRe:VIEWで組んでいます。技術同人誌界隈では実質的な標準ツールとなっている感はあります。比較的簡単に技術書然とした体裁になりますので使っている人も多いでしょう。執筆者の側とすれば、Markdownライクに書くだけでpdf原稿に組版してくれる魅力的なツールですし、テキストベースですからGitHub等での原稿管理も楽ちんです。一方で編集者の側からすれば、機能がかなり限られていて、ちょっとした変更をしたくとも融通が利かないという面もあります。

さて、Re:VIEW原稿では、扉(部を区切るためのページ。第2部:スポンサー原稿　といった特別なページ。)をつけたりすることは案外難しいので、本文原稿だけを出力するにとどめ、扉は別に作ることをお勧めします。その辺りをReviewでやろうとすると、かなり大変になります。

同様に、ノンブルの調整もかなり大変です。もちろんRe:VIEWのマクロをいちから読み解いて行けばどこかに書いてあるはずですが、わかりやすく設定に書いてあったりはしません。（実際本稿執筆時点では私はわかっていません）

ですから、標準でPDFを書き出してしまい、ノンブルを一旦除去してしまう方が簡単です。なおPDF内の文字編集にはAdobe Acrobatが必要です。無料版であるAdobe Readerでは編集機能がかなり制限されてしまいます。そのほかのPDF編集ツールで可能かどうかについては確認していません。PDFは書き込む（追記する）ことは簡単でも、削除したりすることにはかなり制限が入ります。フリーのツールではできないことも多いので、やはり編集長はAcrobat(有料版)を持っておくといろいろ便利です。

なお、どうしてもAdobe Acrobatがない場合は、注釈ツールを用いて既存のノンブルをマスキングしてしまうという方法もあります。ですが既存のノンブルは残ってしまいますから、あとで悪さをする可能性があります。マスクが何らかの理由でズレてしまい下の文字が出てきてしまうなどが考えられますから、Acrobatでノンブル自体を手動で消去する方が確実です。

なお、ページ数が多い場合は、Re:VIEWからページ数を表示しない形式にしてしまいましょう。ToDo：ノンブル周りの設定を調べる。

個人的には、ツールはあくまでツールであり、ツールと格闘することだけが編集長の仕事ではありません。割り切って、複数のツールを使い分け、編集をサクサク進める方が良い場合も多いでしょう。

### Adobe Illustratorまたはトンボ付きPDF
企業広告などで.ai形式またはトンボ付きのPDF原稿が提出されることがあります。印刷界隈の原則はむしろこちらで、印刷原寸トンボなしのPDF原稿の方が例外です。トンボをつけるのは印刷範囲を明確にするためです。また印刷範囲はどうしてもズレが出てしまいますので、実寸でデータを作り印刷すると周囲にわずかな白枠が出てしまうことがあります。そこで実寸から数ミリ外側まで背景画像を引っ張ってある場合があります。これを塗り足しといいます。通常安全率を見て３mm取ることが多いようです。

さて、塗り足し・トンボのある原稿に対する対処です。

塗り足し・トンボを削除して原寸原稿に変換してしまうという手があります。これが一番楽です。楽は楽ですが、背景・テクスチャのあるページでは印刷・断裁のわずかなズレにより周囲に白い部分がわずかに出てしまうことがあります。

そのまま合体させてしまうという手もあります。原稿順が変わってしまったりするリスクもありませんが、単一のPDF内で原稿サイズが変わるなど、編集作業において若干面倒が生じることがあります。印刷所によっては嫌がられる場合もあるでしょう。

サイズ違い原稿を別ファイルのままおいておくのはどうでしょう。印刷所での作業や確認事項が増える傾向にありますが、印刷データ上のリスクは低いです。

どの形態とすれば良いのかは、印刷所に相談してみると良いでしょう。今回は、３とする方向で印刷所と調整中です。

## サークルアピール
技書博ガイドブックには、各サークルのアピールページがB5の1/2あります。サークルカットには書ききれない本の内容やBooth等の頒布チャンネルへの誘導などを想定しています。

これは、編集の労力を軽減するため、Google Slideに説明とテンプレートを用意しています。編集部にとっては、順番の入れ替えや配置番号の入力が楽です。テンプレートでダミーのサークル配置番号を入れておき、あとでテキストボックスをコピペすれば編集が完了するという状況は想像以上に楽です[^No]。

[^No]: 画像やPDFの”同じ位置”にテキストボックスを埋め込むのはかなり面倒です。（スマートなやり方を知りません）

各サークルは当該スライドに直接記入するだけで提出が完了しますし、画像や文字の配置も任意です。またPDFや画像として書き出す手間および解像度に気を配る必要もありません。

また各サークルへのリバイズ指示も簡単です。これまでなったリバイズ指示としては、元画像の解像度が低いためジャギーが出る。誤植がある。などです。


## PDFを統合する

個別ベージを全てPDFにしたら、次はPDFの統合です。

CubePDFやAcrobatなどのPDF編集ソフトで統合します。ページ順は任意に入れ替え可能ですし、差し込みも可能ですから、全ての原稿ファイルを統合し、最終形とします。

次に、目次を作ります。自動でできると良いのですが、原稿形態が異なるので手動とならざるをえないですね。頑張りましょう。GoogleSlideで作っていますので、そこに手動で入力します。結合後に目次の行数が増えて２ページになったりすると、あとでノンブルづけに苦労しますから、目次にあげる項目の漏れには注意しましょう。案外忘れがちなのが、章扉やまえがきあとがきなどです。これらも忘れないように現段階で入れておきます。

次に一旦合体したPDFに通しでノンブルを入れます。Acrobatの編集＞ヘッダ＞ベージ番号で入れられます。あるいはPDF編集ツールにもあります。

次に、ページを手動で拾って目次に入れます。これを自動化することができれば楽なのですが・・・やり方がわかりません。

最後に、更新した目次を合体、入稿用PDFが完成します。

## まとめ

一つのソフトで完結させることができれば良いのですが、現状それはなかなか難しいのが現状です。


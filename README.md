# Password Generator

https://bx19tri.github.io/pw_gen/

## 概要
* 固定文字列(Master pass phrase)とサービスごとのキーワード(Modifier)
  の組み合わせのダイジェストをパスワードとする
* 固定文字列は日本語でも可
* パスワードはアルファベットと数字だけで生成。記号は含めない
* 長さは16文字固定
* 単一の index.html にcss/javascript を含む
  * ブラウザ右クリックの「ページのソースを表示」で全ソースコードを確認可能
* ローカルで計算するだけ。サーバーへの通信はない
* sha512 を 5万回繰り返す。500msec 程度
  * 念の為の Brute-force attack 対策

![PW_GEN](pw_gen.png)

## To Do
* パスワードの長さを変更するUIの追加
* 固定文字列を端末に記録
  * セキュリティの弱点になりうるのでやらない
* ``<INPUT type="password">`` で入力文字を非表示
  * ASCIIしか入力できなくなるのでやらない


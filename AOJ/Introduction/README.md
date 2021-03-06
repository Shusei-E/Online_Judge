# Link
* [ITP1](http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ITP1)

# 使える技術
* 空白のあるinput: ITP1_1_C.Rectangle	
* 割り算の値の処理: ITP1_1_D.Watch
* printfでの出力: ITP1_2_C.SortingThreeNumbers
  * `printf("%d %d %d", a, b, c);` / [Reference](http://www9.plala.or.jp/sgwr-t/c/sec05.html)
	* [出力フォーマット指定子](http://www.k-cube.co.jp/wakaba/server/format.html)
* Sort: ITP1_2_C.SortingThreeNumbers
* vectorの最大値、最小値、総和 (非常に大きな数の取り扱い)
	* ITP1_4_D.MinMaxAndSum
	* ITP1_6_A.ReversingNumbers
* switch文
	* ITP1_6_B.FindingMissingCards
* Dynamic allocation of multidimensional array
	* ITP1_6_D.MatrixVectorMultiplication
* 文字列の扱い
	* ITP1_8_A.TogglingCases
	* `int num = ch - 'a';  // 文字 ch の番号`
	* 行の取得: `getline(cin, s1);`
	* EOFまで読み込む --> ITP1_8_C.CountingCharacters (ちなみにEOFはCtrl-D)
	* 単語ごとの処理 --> `ITP1_9_A.FindingAWord`の`istringstream`
	* 大文字/小文字 --> `#include <algorithm>`を読み込んでおいて`std::transform(str.begin(), str.end(), str.begin(), ::tolower);` (`ITP1_9_A.FindingAWord`)
	* Slice --> `ITP1_9_B.Shuffle` (恐らく文字と文字の間でindexされていてPythonと同じでは)
	* string型だったら、`<, >, ==`で辞書順の大小比較ができる (`ITP1_9_C`)。
	* 文字列の任意の箇所でreplace, reverse, print: `ITP1_9_D: Transformation`
* 数字の出力: 小数点の取り扱い --> `ITP1_10_A`
* 変数の宣言
	* 複数の変数の値を0に: `int e1,e2,e3 = {};`
* オブジェクトの値の入れ替え: [std:swap](http://kaworu.jpn.org/cpp/std::swap)
	* `int a = 0, b = 100; std::swap(a,b);`

# 上手な別解あり
* ITP1_6_B.FindingMissingCards
	* indexがズレる問題 --> 配列の方を大きくして対処

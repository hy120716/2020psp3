# 課題1 レポート
35319031　橋口裕太


## 課題
長崎県にある市町村別人口データを読み込み、IDを用いて検索し、該当する市町村名、人口を出力するプログラムを作成する。

1. 使用するデータ
長崎県の人口データは、nagasaki.csvに保存されている。
nagasaki.csvには、csv形式で以下のデータが含まれる
    - ID
    - 県名
    - 市町村名
    - 人口
    - 男性人口
    - 女性人口

    長崎県の市町村別人口データは、下記に構造体の配列に読み込まれる。

```C: 市町村別データ構造体
typedef struct {  
    int id;  
    char pref[13];  // UTF-8対応  
    char name[19];  // UTF-8対応  
    int population;  
    int m_population;  
    int f_population;  
} City;  
```



2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。  
   (1) LinearSearch：IDをキーとし、リニアサーチで市町村を検索する。  
    [入力]
    - int key: 検索する市町村のID
    - City arrayCity[]: 検索対象の都市別人口データ(配列)
    - int size: データの数  

    [出力]  
    - return値: IDが合致した配列データのindex。IDが一致するデータがない場合は-1。

    (2) BinarySearch: IDをキーとし、バイナリサーチで市町村を検索する。  
    [入力]
    - int key: 検索する市町村のID
    - City arrayCity[]: 検索対象の都市別人口データ(配列)
    - int left: バイナリサーチを行う配列のindex(左端)
    - int right: バイナリサーチを行う配列のindex(右端)  

    [出力]  
    - return値: IDが合致した配列データのindex。IDが一致するデータがない場合は-1。


3. 補助関数
以下の関数はすでに実装されており、利用することができる。  
- PrintCity: 特定の市町村別人口データを出力する  
- PrintArray: 市町村別人口データをすべて出力する  
- LoadData: 市町村別人口データを読み込み、City型の配列に格納する  
- main: メイン関数。データをロードし、リニアサーチ、バイナリサーチを呼び出す  


## ソースコードの説明
l.68,69:indexを表す変数posと結果の変数resultを宣言
l.71~76:リニアサーチなので、posが0から配列のサイズ分まで、keyと配列のidが一致するものを探索し、もし一致するものがあればresultにそのindexであるposを代入する
l.77:resultの値を返す

l.84,85:indexを表す変数posと結果の変数resultを宣言
l.87~97:バイナリサーチなので、配列の右端のindexから左端のindexを引いたものが0以上であるとき（リストに要素が存在する場合）、posをリストの中央して、keyとindexがpos時の配列のidが一致したら、その時のposをresultに代入し、ループを抜ける
もしkeyがpos時の配列のidより大きければ探索対象の範囲の左端のindexのleftをpos+1にする
もしkeyがpos時の配列のidより小さければ探索対象の範囲の右端のindexのrightをpos-1にする
これを繰り返し、keyとindexがpos時の配列のidが一致するものを探索
l.98:resultの値を返す



## 出力結果

```
===== linear search =====
City ID?42207
42207, 長崎県, 平戸市, 31920, 14874, 17046

===== binary search =====
City ID?42207
42207, 長崎県, 平戸市, 31920, 14874, 17046

===== linear search =====
City ID?37098
city was not found

===== binary search =====
City ID?49087
city was not found

```

## 修正履歴


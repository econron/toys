## やったことのログ

```sh
## ragelのインストール
brew install ragel

## helloにマッチするかチェックする状態機械をビルドして実行
ragel hello.rl -o hello.c   # .rl → .c に変換
gcc hello.c -o hello        # 普通のCとしてコンパイル
./hello helloworld          # → match!
./hello goodbye             # → no match

### そのままgraphvizでチェックする
ragel -V hello.rl > hello.dot
dot -Tpng hello.dot -o hello.png
open hello.png    # Linuxなら xdg-open

## counterをビルドして実行
ragel vowels.rl -o vowels.c
gcc vowels.c -o vowels
./vowels "hello world"   # vowels: 3

### そのままgraphvizでチェックする
ragel -V vowels.rl > vowel.dot
dot -Tpng vowel.dot -o vowel.png
open vowel.png 

## hello || hi　の状態機械
ragel hello-hi.rl -o hello-hi.c
gcc hello-hi.c -o hello-hi  
./hello-hi hi # match
./hello-hi high # no match

ragel -V hello-hi.rl > hello-hi.dot
dot -Tpng hello-hi.dot -o hello-hi.png
open hello-hi.png
```
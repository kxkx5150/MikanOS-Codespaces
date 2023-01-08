# MikanOS-Codespaces

GitHub Codespaces

<br><br><br><br>

## [vsocde devcontainer版はこちら](https://github.com/kxkx5150/MikanOS-devcontainer)


<br><br><br><br>



深い理解の為には買いましょう。  

## [ゼロからのOS自作入門 単行本](https://www.amazon.co.jp/%E3%82%BC%E3%83%AD%E3%81%8B%E3%82%89%E3%81%AEOS%E8%87%AA%E4%BD%9C%E5%85%A5%E9%96%80-%E5%86%85%E7%94%B0-%E5%85%AC%E5%A4%AA/dp/4839975868)

[Youtube 自作OS](https://www.youtube.com/watch?v=PvmLLKnIzcs&list=PLbBGNsln3DxTLHB9GFM6_drAJ1JQXIOud&index=1)

<br><br><br><br>


全日程のソース同梱

![Screenshot from 2023-01-07 15-50-59](https://user-images.githubusercontent.com/10168979/211135361-58a5176e-a5fd-4eaf-bc4b-7f8b641d4d7c.png)


<br><br><br><br>




https://user-images.githubusercontent.com/10168979/211178773-447129bb-4510-4ced-9af4-71f876518817.mp4





## GitHub Codespaces

Web上で 開発環境を構築


Use this templateボタンを押して、リポジトリを作ってCodespacesで開いて下さい。  

環境構築が終われば、web上のvscodeで開発出来ます。

<br><br><br><br>

### QEMUを起動したら、ターミナルの横のポートをクリックして、ブラウザで確認

ポート番号は5900ではなく**6088**です


<br><br><br><br><br><br>

## Codespacesの使用状況を確認

https://github.com/codespaces  

無料で済ませたいなら、使った後は、停止してるか確認  
無駄なコンテナは削除しましょう

停止は  
codespecesをクリックして、メニューから停止

![c](https://user-images.githubusercontent.com/10168979/209823266-8ae47f4e-f86e-44a7-a013-dd480fa6c3ad.png)


<br><br><br><br><br><br>


## ビルド方法

target.txt、buildenv.shは起動時に読み込むようにしました。  
調子が悪いなら再度読み込んで下さい。  





<br><br><br><br>

### 各日付 (day***) のサブフォルダに移動して下さい。

<br><br><br>

カーネル + uefi + app をビルド + qemuで確認
```shell
make run
```


カーネル + uefi + app をビルド
```shell
make
```


カーネル
```shell
make kernel
```


app
```shell
make app
```


掃除
```shell
make clean
```


qemuで確認
```shell
make qemu
```




<br><br><br>
<br><br><br>


## MikanOS

<br>

同梱のソースは最新では無いので勉強用と考えて下さい。  
機能追加もされており、機能追加に参加したい方は下記へ

<br><br>

### 最新のソースは
[uchan-nos/mikanos](https://github.com/uchan-nos/mikanos)


<br><br><br>
<br><br><br>
<br><br><br>

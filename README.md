# TLClipEdit
TLClipEdit  
Copyright (C) 2020 TranslucentFoxHuman (半透明狐人間) 
 
TLClipeditは、簡単なテキスト形式のクリップボードの内容を編集、閲覧する作業を簡単にするツールです。 
以下の機能をサポートしています。
・クリップボードのテキスト内容の表示 
・クリップボードにテキストを書き込み 
・一時的に履歴として、クリップボードの内容を留める 

# このリポジトリについて
このリポジトリ内において、「tlclipedit-0.1.tar.gz」は、インストール可能なtarballパッケージです。こちらをダウンロードしてお使いください。

# 既知の問題
uiファイルが読み込めない問題が発覚し、現在、uiファイルの場所を"/usr/local/share/tlclipedit/ui/tlclipedit.ui"の絶対パスで指定することで回避しています。よって、ファイルをデフォルトの場所以外にインストールしないでください。起動できなくなります。
 
# インストール手順 
まず、このアーカイブをすべて解凍し、解凍先のフォルダで端末を開きます。 
そして、以下のようにしてください。 
 
./configure 
make 
sudo make install 
 
configureの段階で失敗する場合、パッケージが不足している可能性が考えられます。 
このソフトウェアには、以下のパッケージが必要です。(Ubuntuの場合) 
gcc 
make 
intltool 
libgtk-3-dev 
これらを先にインストールしてから、再度configureを試みてください。 
詳しくは、INSTALLファイルをご覧ください。 
 
# ライセンス 
このプログラムはフリーソフトウェアです。あなたはこれを、フリーソフトウェア財団によって発行されたGNU 一般公衆利用許諾書（バージョン3か、それ以降のバージョンのうちどれか）が定める条件の下で再頒布または改変することができます。 
 
このプログラムは有用であることを願って頒布されますが、*全くの無保証*です。*商業可能性の保証や特定目的への適合性は、言外に示されたものも含め、全く存在しません。*詳しくはGNU 一般公衆利用許諾書をご覧ください。 
あなたはこのプログラムと共に、GNU 一般公衆利用許諾書のコピーを一部受け取っているはずです。もし受け取っていなければ、<https://www.gnu.org/licenses/> をご覧ください。 
 
TLClipEdit is free software: you can redistribute it and/or modify it 
under the terms of the GNU General Public License as published by the 
Free Software Foundation, either version 3 of the License, or 
(at your option) any later version. 
 
TLClipEdit is distributed in the hope that it will be useful, but 
WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU General Public License for more details. 

You should have received a copy of the GNU General Public License along 
with this program.  If not, see <http://www.gnu.org/licenses/>. 

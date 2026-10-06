# 纵windows亡 Linux仍不悔（哭

## 序列九：算者—— 命令行参数与路径

### 1.

Q1.解释什么是绝对路径，什么是相对路径？

A1.一个是从根目录开始算 一个是从当前工作目录开始算

Q2.假设你现在正处于 /home/lin/workspace/，请分别写出前往 /var/backups/turing/ 的绝对路径命令和相对路径命令（假设 cd 命令还能用）。

A2.

绝对：cd /var/backups/turing/
相对：cd ../../../var/backups/turing/

碎碎念：原本打算用wsl和虚拟机一块练手的 但感觉自己会手笨给自己磁盘文件删了 毕竟能访问到 所以还是用虚拟机算了

### 2.

Q1.简要解释主函数参数 argc 与 argv[] 的含义是什么。

A1.argc是有参数和程序名的个数 argv[]是字符串数组 里面包含了参数和程序名

Q2.针对上述命令，请问 argc 的值是多少？argv[0]、argv[1]、argv[2] 分别指向什么字符串？

A2.2 "cd" "../../../var/backups/turing/" NULL

## 序列六：算王—— 重建 ls 命令与位运算

### 1.


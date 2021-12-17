红黑树的特性:
（1）每个节点或者是黑色，或者是红色。
（2）根节点是黑色。
（3）每个叶子节点（NIL）是黑色。 [注意：这里叶子节点，是指为空(NIL或NULL)的叶子节点！]
（4）如果一个节点是红色的，则它的子节点必须是黑色的。
（5）从一个节点到该节点的子孙节点的所有路径上包含相同数目的黑节点。
对于插入情况的核心思路：将红色节点移到根节点，然后将根节点设为黑色，否则变色处理。

![image-20211027223733618](C:\Users\86198\AppData\Roaming\Typora\typora-user-images\image-20211027223733618.png)

![image-20211027223810672](C:\Users\86198\AppData\Roaming\Typora\typora-user-images\image-20211027223810672.png)

![image-20211027223831229](C:\Users\86198\AppData\Roaming\Typora\typora-user-images\image-20211027223831229.png)

![image-20211027223936885](C:\Users\86198\AppData\Roaming\Typora\typora-user-images\image-20211027223936885.png)




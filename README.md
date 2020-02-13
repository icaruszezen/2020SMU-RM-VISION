# RM_VISION
#### 尝试使用OpenCV 4的API，在zezen童鞋的基础上删除了Rune的代码，存入deleted文件夹中
## 环境改变：
### IDE:Visual Studio Code
### CMake or QMake
### clang++ + llvm
希望能够用到Videocapture的原生API，而非Dji写的RMVideoCapture。</br>
但是有一个问题，RMVideoCapture好像有个热更换（720P->480P）,是通过底层V4L实现的。</br>
如果强行使用原生VideoCapture类可能无法完成分辨率的更换。</br>
ps: OpenCV4的原生API里面已经支持了V4L2</br>
### 还是仅供参考


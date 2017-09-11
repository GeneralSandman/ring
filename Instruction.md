# 开发文档
## 各种模块的介绍

> ### 1.Reader类
- 用文件名初始化

```
Reader(const std::string &f);
```

- 读取一行存到string中

```
std::string readLine(void);
```

- 获取读取操作的所在行数
```
int getCurrLineNu(void);
```
- 是否还能读取更多的内容
```
bool haveMore(void);
```
- 获取文件总行数
```
int getLineNu(void);
```
- 将读取操作重定向至文件头
```
void resetToHead(void);
```

> ### 2.
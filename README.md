# LoCi SDK v1.3

## 基本说明：
- `LoCi`，即`LocateIP`的简写，是一个用于解析`IP归属地数据库`的引擎。通过纯C代码写成，一切为了追求效率，非常适合集成到您的程序中。
- 我们不止解析其它格式的数据库，我们也有自己的数据库格式，更为强大、安全和快速。(尚未完成)
- 不同的数据库都抽象为`ipdb`这个结构。使用`ipdb.h`中的通用函数进行操作。使用示例可见`test.c`文件

## 目前完成的功能：
- 纯真数据库`QQWry.Dat`的解析。（默认GB2312编码）
- 17mon数据库`17monipdb.dat`的解析。（默认UTF8编码）
- 解压为txt文件，方便查看数据库所有内容，需要`ipdb`提供了遍历接口。
- txt文件数据库的解析，方便生成自定义数据库。（IP必须有序）
- 纯真数据库`QQWry.Dat`的生成，需要`ipdb`提供了遍历接口。
- 数据库增量补丁的生成，需要两个`ipdb`提供了遍历接口。老数据库+新数据库->增量补丁（一个很小的文件）
- 数据库增量补丁的应用，需要旧的`ipdb`提供了遍历、定位接口。老数据库+增量补丁（一个很小的文件）->新数据库
- 纯真数据库自动更新解析，配合增量补丁，方便打造自己的更新服务器。

## 因为跨平台的原因，我们不提供：
- 编码转换。
- 文件读取。
- 网络下载。

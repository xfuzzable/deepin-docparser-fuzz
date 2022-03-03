# deepin-docparser-fuzz

## 编译项目及目标程序
```
./build.sh
```

## 运行模糊测试
### 测试解析 docx 文档功能
```
./fuzz_docx.sh 
```
### 测试解析 pdf 文档功能
```
./fuzz_pdf.sh
```
### 测试解析 pptx 文档功能
```
./fuzz_pptx.sh
```

## 模糊测试种子数据
### 数据存放在当前文件夹下的 data 目录，添加时往 data 中相对应的文件夹中添加文件种子文件。


## 创建新的功能测试
### 在 build.sh 中编译目标文件的列表中添加一个尾缀（如：xlsx/txt）, 即可生成相对应的目标文件。编写 fuzz 脚本，添加种子数据，开始测试。

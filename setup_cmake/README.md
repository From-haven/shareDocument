# Copy file Cmake list (có vị dụ mẫu và build bằng c++26)
# build như project AI
``` bash
cmake -B build
```

``` bash
cmake --build build -j$(nproc)
```
# chạy debug
- vì debug chạy bằng compiler và cmake chỉ là công cụ để gọi, nên có 2 cách

## cách 1
- ấn vào con bọ ở phía dưới bên trái màn hình (rồi để nó tự quét)
- nhớ chọn ở mục clangd

## cách 2
- B1. sài file lauch.json ".vscode/launch.json" source code để cùng một thư mục
- B2. bấm Ctrl + Shift + D , chọn (gdb) Launch CMake Target và bấm nút Play màu xanh lá *(hoặc nhấn F5)* để chạy debug.

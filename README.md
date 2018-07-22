# Giải thích các methods

---

## Các methods trong `game.h`

```cpp
void EachDataSaved(ifstream &fin, const int &number) const;
//Hàm đọc nội dung file save lên để hiển thị ra menu (hiện tại chỉ gồm tên + level).
```

```cpp
void PrintSaveData() const;
//Hàm này gọi hàm trên thực thi tương ứng với 6 file save, thay vì phải lặp lại code tương tự 6 lần trong 1 hàm.
```

```cpp
void LoadData(const int &number);
//Như tên, hàm này nhận vào con số từ 1 - 6 tương ứng 6 file save, đọc nội dung file save và cập nhật lại data game.
```

```cpp
void SaveData(const int &number);
//Hàm này save data xuống file.
```

```cpp
void StartGame();
//Đây là hàm quan trọng nhất game, nó sẽ khởi tạo mỗi làn đường mấy chiếc xe / con thú bằng 4 vòng for, sau đó tạo một luồng cho tất cả các xe, thú này di chuyển đồng thời tạo một vòng while (true) điều khiển con nhân vật.
```

```cpp
void AllMove(const int &level);
//Hàm này để ráp vào luồng của StartGame ở trên, chịu trách nhiệm gọi tuần tự tất cả phương tiện di chuyển đồng thời với điều kiện biến STOP chưa true.
```

```cpp
void Stop(thread* sub_thread);
//Hàm này để dừng một luồng khi nó đang chạy, dừng là dừng luôn k phải chỉ pause.
```

## Hàm main

```cpp
try {
    //...
}
catch(...) {
    return EXIT_FAILURE;
}
//Khi gặp bất cứ một lỗi gì không quan tâm nó là cái gì, out game ra :)
```

```cpp
switch() {
    case 1:
        //...
        break;
}
//4 tuỳ chọn ngoài màn hình chính.
```

## Các methods trong `console.h`

```cpp
static void BackgroundMusic();
//Hàm này chèn nhạc nền, lưu ý là mỗi bài nhạc sẽ phải viết một hàm riêng thì hàm này không biết cho nhận tham số kiểu gì. Lưu ý nữa là chỉ chấp nhận file WAV.
```

```cpp
static void FixConsoleWindow();
//Hàm này sẽ fix lại màn hình k cho phóng to thu nhỏ gì hết, đảm bảo giao diện không bị sắp xếp lung tung.
```

```cpp
static void ShowConsoleCursor(const bool &choose);
//Hàm này để ẩn / hiện con nháy trong quá trình game chạy.
```

```cpp
static void GotoXY(const int &x, const int &y);
//Khỏi giải thích nhỉ, hàm đi đến một vị trí quy định trong console.
```

```cpp
static void SetText(const string &text, const int &x, const int &y);
//Đi tới vị trí XY in chữ ra.
```

```cpp
static void Choose(const int &x, const int &y);
//Đi tới XY cài một con trỏ để cho người dùng biết đang chọn nút nào, vị trí XY này cũng dùng để giúp xác định người dùng muốn chọn chạy chức năng nào trong game.
```

```cpp
static void Border(const int &width, const int &height, const int &x, const int &y);
//Vẽ một border với 4 tham số như code.
```

```cpp
static void Button(const string &text, const int &width, const int &height, const int &x, const int &y);
//Vẽ một button với tham số text là tên button.
```

```cpp
//Các methods có chữ "Menu" chủ yếu là vẽ giao diện, có thể k cần care.
```

```cpp
static int ProcessMainMenu();
//Xử lý trả về 1 trong 4 lựa chọn ngoài màn hình chính cho hàm main chạy lệnh tương ứng với lựa chọn đó.
```

```cpp
static bool Accept();
//Hàm này dùng nhiều, trong các lựa chọn sẽ có 2 nút (1 nút Back để quay về k chọn cái đó nữa, 1 nút Accept hay OK gì đó để tiếp tục chơi), thì bool này nếu true tức là tiếp tục, false là Back trở lại.
```

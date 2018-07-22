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


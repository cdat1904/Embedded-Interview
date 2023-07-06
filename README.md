# Embedded-Interview
<details>

<summary>COMPILER</summary>
Quy trình dịch là quá trình chuyển đổi từ ngôn ngữ bậc cao sang ngôn ngữ đích (ngôn ngữ máy) để máy tính có thể hiểu và thực thi. Ngôn ngữ lập trình C++ là một ngôn ngữ dạng biên dịch. Chương trình được viết bằng C++ muốn chạy được trên máy tính phải trải qua một quá trình biên dịch để chuyển đổi từ dạng mã nguồn sang chương trình dạng mã thực thi. Quá trình được chia ra làm 4 giai đoạn chính:
    
![image](https://codelearn.io/Media/Default/Users/Darksider/ssj/maxresdefault.jpg)
	
	
HOẠT ĐỘNG

1. Giai đoạn tiền xử lý – Preprocessor
Bộ tiền xử lý có nhiệm vụ thực hiện:

- Nhận mã nguồn
- Xóa bỏ tất cả chú thích, comments của chương trình
- Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý
Chúng ta có thể bắt lỗi ngay ở giai đoạn này với việc sử dụng một cách hợp lý các chỉ thị #if và #error. Bằng cách sử dụng option -E của trình biên dịch như bên dưới, chúng ta có thể dừng quá trình biên dịch ngay ở giai đoạn tiền xử lý nếu có lỗi ở giai đoạn này.

Ví dụ: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.
![image](https://codelearn.io/Media/Default/Users/Darksider/ssj/Screenshot%202020-09-22%20092248.png)
	
Sau khi thực hiện tiền xử lý
	
![image](https://codelearn.io/Media/Default/Users/Darksider/ssj/Screenshot%202020-09-22%20092317.png)
	

2. Compilation (biên dịch)

- Phân tích cú pháp (syntax) của mã nguồn NNBC.
- Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.

![image](https://codelearn.io/Media/Default/Users/Darksider/ssj/Screenshot%202020-09-22%20094157.png)
	
3. Công đoạn dịch Assembly

- Dich chương trình => Sang mã máy 0 và 1
- Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.
	
4. Giai đoạn Linker

Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.
    
</details>

<details>
<summary>PHÂN VÙNG NHỚ</summary>
	
<img width="400" alt="image" src="https://i0.wp.com/media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg?resize=449%2C343&ssl=1">

## Phân vùng Text:
- Quyền truy cập chỉ Read và nó chứa lệnh để thực thi nên tránh sửa đổi instruction.

- Chứa khai báo hằng số trong chương trình (.rodata)
```
// Ví dụ : chỉ đọc data
const int a = 9;
char *arr = "Hello";
```
## Phân vùng Data:
- Quyền truy cập là read-write.

- Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.

- Được giải phóng khi kết thúc chương trình.
```
#include <stdio.h>

int x = 10; // biến toàn cục
static int a = 15; // biến static toàn cục

void test(){
 static int b = 10; // biến static cục bộ
 a = a + 20;
 prinf("test: %d\n", a);
}
int main (){

 test();
 a = a +15;
 prinf("main: %d\n", a);
 return 0;
 // Result: test = 35, main = 50
```
## Phân vùng BSS:
- Quyền truy cập là read-write.

- Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.

- Được giải phóng khi kết thúc chương trình.
```
static int a ; // biến static toàn cục phân vùng bss
/* khi giá trị được khởi tạo vd: a = 10 thì nó vẫn ở phân vùng bss */ 
void test(){
 static int b ; // biến static cục bộ
}
int main (){
}
```
## Phân vùng Stack:
- Quyền truy cập là read-write.

- Được sử dụng cấp phát cho biến local, input parameter của hàm,…

- Sẽ được giải phóng khi ra khỏi block code/hàm.
```
// int a, int b là input parameter
int sum(int a, int b){
  int c; // biến cục bộ ở phân vùng stack
  c = a + b;
  return c;
}
```
## Phân vùng Heap:
- Quyền truy cập là read-write.

- Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc,…

- Sẽ được giải phóng khi gọi hàm free,…
```
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void test1(){
  char arr[3]; // biến toàn cục
  printf("Dia chi arr: %p\n", arr);
}

void test2(){
/*
 Khi khai báo kiểu malloc, các ô nhớ sẽ được giữ nguyên bộ nhớ ban đầu (draf data hay dữ liệu rác).
 Kiểu trả về là con trỏ void (không có giá trị), tham số truyền vào là  size tính bằng byte.
 Vì hàm malloc trả về dạng void, vậy ta cần ép kiểu cho nó trở về đúng kiểu con trỏ mà ta sử dụng.
 Vì char có 1 byte nên khai báo sẽ được cấp 3 byte tương ứng 3 phần tử.
*/
  char *arr = (char*)malloc(sizeof(char)*3);
  // arr = (char*)realloc(arr,(sizeof(char)*5) // thay đổi kích thước mảng 5 byte tương ứng 5 phần tử
  printf("Dia chi arr: %p\n", arr);
  free(arr);
}

int main(){
  test1();
  test1();
  test2();
  test2();
}
/*
Result: khi chưa sử dụng lệnh free cho hàm malloc
Dia chi arr: 0061FF0D : khi gọi test1 lần 1 sau khởi tạo xong nó sẽ thoát ra và thu hồi vùng nhớ 
Dia chi arr: 0061FF0D : khi gọi test1 lần 2 nó khởi tạo địa chỉ trước đó vì địa chỉ đó vẫn còn trống.
Dia chi arr: 00BA2F20 : do malloc được lưu ở phân vùng Heap nên nó không thể tự thu hồi 
Dia chi arr: 00BA2F30

Result: khi sử dụng lệnh free cho hàm malloc
Dia chi arr: 0061FF0D
Dia chi arr: 0061FF0D
Dia chi arr: 00AD2F20
Dia chi arr: 00AD2F20
*/
```
## Sự khác nhau giữa bộ nhớ Heap và bộ nhớ Stack :
- Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
- Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch
- Vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.
- Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).
- Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow).
</details>
    
 <details>
 <summary>MACRO - FUNCTION - INLINE</summary>
     
 ## Macro 
 - Macro không phải là hàm, cũng không phải là biến mà nó chỉ là 1 định nghĩa.
 - Macro được diễn ra ở quá trình tiền xử lý (preprocessor).
 - Thay thế định nghĩa macro vào đoạn code đã gọi.
 - VD: #define SUM(a,b)     (a+b)
       - Preprocessor khi gặp bất kỳ lời gọi SUM(first+last) nào thì thay ngay bằng (first+last)

     
 **VD1:**
 ```
 #define MAX 10
 Preprocessor khi gặp bất kỳ lời gọi MAX nào thì thay ngay bằng 10.
     
 #define SUM(a,b) a + b //SUM(a,b) gọi là định nghĩa
 Preprocessor khi gặp bất kỳ lời gọi SUM(first,last) nào thì thay ngay bằng (first+last).
 
 ```
     
 **VD2:**
 ```
  '\' trong Macro dùng để liên kết nội dung dòng bên dưới 
  #define CREATE_FUNC(ten_ham, noi_dung)    \
  void ten_ham(){                           \
     printf("%s\n",noi_dung);               \
  }
  CREATE_FUNC(test,"this is test\n"); // tạo ra hàm test
   /*
   void test(){                           
     printf("%s\n","this is test\n");       
  }
   */
  CREATE_FUNC(test2,"this is test2\n"); // tạo ra thêm hàm test2
  
 ```
 ## Function
- Khi thấy hàm được gọi, compiler sẽ phải lưu con trỏ chương trình Program Couter (PC) hiện tại vào Stack Pointer; chuyển Program Counter tới hàm được gọi, thực hiện hàm đó xong và lấy kết quả trả về; sau đó quay lại vị trí ban đầu trong stack trước khi gọi hàm và tiếp tục thực hiện chương trình.
- Như có thể thấy, các này khiến chương trình tốn thời gian hơn là chỉ cần thay thế đoạn code đã được compile (cách của inline function).
     
**VD: giả sử trường hợp 8 bit**
```
Trường hợp đang ở dưới thì khi đến 0x03 thì nó gặp 1 hàm. 
Lúc này nó sẽ lưu 0x03 vào Stack Pointer và PC nó sẽ vào hàm A để chạy từ 0xc1 đến 0xc6.
Sau khi PC chạy xong hàm A, lúc này nó sẽ vào Stack Pointer để lấy 0x03 gán cho PC và tiếp tục chạy từ 0x03 đến 0x08.
 
0x01   main (){           
0x02    while(1){     
0x03     A();
 .    
 .      }
0x08  }

0xc1    void A(){
  .
  .    
0xc6   }
```

## Inline
- Được xử lý bởi compiler
- Được khai báo với từ khóa inline
- Khi compiler thấy bất kỳ chỗ nào xuất hiện inline function, nó sẽ thay thế chỗ đó bởi định nghĩa của hàm đã được compiler tương ứng. –> Phần được thay thế không phải code mà là đoạn code đã được compiler.
     
## So sánh
- `Macro` đơn giản là chỉ `thay thế đoạn code macro vào chỗ được gọi` trước khi được biên dịch
- `Inline thay thế đoạn mã code đã được biên dịch vào chỗ được gọi`.
- `Hàm bình thường phải tạo một function call`, lưu địa chỉ trước khi gọi hàm vào stack sau đó mới thực hiện hàm và sau cùng là quay trở về địa chỉ trên stack trước khi gọi hàm và thực hiện tiếp chương trình
- `Macro khiến code trở nên dài` hơn rất nhiều so với bình thường `nhưng thời gian chạy nhanh`.
- `Hàm inline cũng khiến code dài hơn`, tuy nhiên nó làm `giảm thời gian chạy chương trình`.
- `Hàm bình thường` sẽ phải gọi function call nên `tốn thời gian hơn inline function` nhưng `code ngắn gọn hơn`.
   
</details>
    
    
<details>
<summary>TOÁN TỬ  / THAO TÁC BIT</summary>
    
- AND (Biểu thức AND): Ký hiệu: `&`.
	| A | B | A & B |
  	|---|---|:---:|
  	|0|0|  0|
  	|0|1|  0|
  	|1|0|  0|
  	|1|1|  1|
    ```c
    unsigned int a = 9;  
	unsigned int b = 8;  
    unsigned int result = a & b;  
	```
 - OR (Biểu thức OR): Ký hiệu: `|`.
	| A | B | A \| B |
  	|---|---|:---:|
  	|0|0|  0|
  	|0|1|  1|
  	|1|0|  1|
  	|1|1|  1|
    ```c
    unsigned int a = 5;  // 0101
	unsigned int b = 3;  // 0011
	unsigned int result = a | b;  // 0111
    ```
- XOR (Biểu thức XOR): Ký hiệu: `^`.
	| A | B | A ^ B |
  	|---|---|:---:|
  	|0|0|  0|
  	|0|1|  1|
  	|1|0|  1|
  	|1|1|  0|
    ```c
    unsigned int a = 5;  // 0101
	unsigned int b = 3;  // 0011
	unsigned int result = a ^ b;  // 0110
    ```
- NOT (Biểu thức NOT): Ký hiệu: `~`, thực hiện phép NOT bit, đảo ngược tất cả các bit của số.
	| A | ~ A |
  	|--|:---:|
  	|0|  1|
  	|1|  0|
    ```c
    unsigned int a = 5;  // 0101
	unsigned int result = ~a;  // 1010 (đảo ngược các bit)
    ```


##
<img width="355" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/02e222c1-e668-4939-a6ea-dd05e7eb746e">

Dịch trái (<<) 4 bit là bỏ đi 4 bit bên trái(ở đầu) và thêm 4 bit 0 vào bên phải(ở cuối)

<img width="357" alt="image" src="https://github.com/Kiet2024/Embedded_interview/assets/133784431/085599a0-6a96-4d58-b47a-507eb1705ee4">

Dịch phải(>>) 1 bit là bỏ đi 1 bit bên phải(ở cuối) và thêm 1 bit 0 vào bên trái(ở đầu)
## Set 1 bit
```bit |= (1 << n); //(n là vị trí bit)```
## Clear 1 bit
```bit &= ~(1 << n);```
## Toggle 1 bit 
```bit ^= (1 << n);```
## Test 1 bit
``` 
// bit & (1 << n)
int bit = 5; // 0101
printf("%s",(((bit & (1<<2)) !=0)?"true":"false"));
 ```
</details>   
 
<details>
<summary>TYPEDEF & ENUM</summary>
    
Typedef được sử dụng để tạo tên mới cho kiểu dữ liệu. 
```
typedef uint8_t u8;
u8 x = 10; // u8 bản chất nó là kiểu uint8_t
 ```
Enum là 1 kiểu dữ liệu người dùng tự định nghĩa. Dùng để gán tên cho các hằng số. Được sử dụng để bạn có thể kiểm soát các hằng số không muốn bị nhầm lẫn trong quá trình sử dụng. Được sử dụng để định nghĩa các mã lỗi, các mã trả về, các biến hằng cần kiểm soát…
```
    typedef enum {
GiaTri1, 
GiaTri2, 
GiaTri3,
…, 
GiaTriN
} TenEnum;
```
</details>
    
    
<details>
<summary>STRUCT - UNION</summary>
 
## Struct
### Định nghĩa
struct là 1 tập hợp các phần tử dữ liệu cùng kiểu hoặc khác kiểu được gộp chung thành 1 nhóm. Các phần tử này được gọi là thành viên của struct.
	
### Cú pháp
```
struct <Tên struct>
{
<Kiểu dữ liệu thành viên số 1> <Tên thành viên số 1>;
<Kiểu dữ liệu thành viên số 2> <Tên thành viên số 2>;
…
};
```
### Sử dụng Struct
- Để truy cập vào các thành viên của struct sử dụng toán tử dấu chấm (.) đặt giữa tên biến kiểu struct và tên thành viên của struct cần truy cập.

- 1 biến thuộc kiểu struct cũng có thể trở thành tham số của 1 hàm.

- Có thể truy cập thành phần của struct thông qua biến con trỏ.
```
#include<stdio.h>
#include <string.h>
 
struct employee {
    int id;
    char name[50];
    float salary;
} e1; // khai bao bien e1
 
int main() {
    // luu tru thong tin employee
    e1.id = 17;
    strcpy(e1.name, "Vinh Tran"); // sao chep string thanh mang char
    e1.salary = 1000;
    // hien thi thong tin employee ra man hinh
    printf("employee 1 id : %d\n", e1.id);
    printf("employee 1 name : %s\n", e1.name);
    printf("employee 1 salary : %f\n", e1.salary);
    return 0;
}
```
 ### Size của Struct
 ```
 // Chương trình tính size của  1 struct
#include <stdio.h>
#include <stdint.h>

struct typeDate
{
    uint8_t arr1[10]; // 1 byte
    uint16_t arr2[7]; // 2 byte
    uint64_t arr3[5]; // 8 byte
    uint32_t arr4[1]; // 4 byte
};

int main ()
{
    printf("Size: %lu", sizeof(struct typeDate)); // result = 72 byte
    return 0;
}
 ```
 
Số byte cần quét trong 1 lần sẽ dựa trên byte lớn nhất trong struct
### Ví dụ 1:
```
struct typeDate
{
  // Số byte cần quét trong 1 lần = 8 byte
    uint8_t arr1[10]; // 1 byte
    uint16_t arr2[7]; // 2 byte
    uint64_t arr3[5]; // 8 byte
    uint32_t arr4[1]; // 4 byte
};
```
### Cách tính số size :

uint8_t có size 1 byte => arr1[10] cần 1*10 = 10 byte để lưu, mà 1 lần quét là 8 byte (byte cao nhất trong struct) 

=> arr1[10] = 10 byte + **6 byte dư** = 10 byte (cần 2 lần quét)

uint16_t có size 2 byte => arr2[7] cần 2*7 = 14 byte để lưu, mà ở trên còn dư 6 byte, nên lúc này cần 1 lần quét là đủ 

=> arr2[7] = **6 byte (byte dư ở arr1)** + 8 byte = 14 byte.

uint64_t có size 8 byte => arr3[5] cần 8*5 = 40 byte để lưu 

=> arr3[5] = 40byte ( 5 lần quét).

uint32_t có size 4 byte => arr3[1] cần 4*1 = 4 byte để lưu, nên chỉ cần 1 lần quét

=>  arr3[1] = 4 byte + 4 byte dư = 8 byte

==> tổng size = 10 byte + 14 byte + 40 byte + 8 byte = 72 byte

### Ví dụ 2:
```
struct typeDate
{
  // Số byte cần quét trong 1 lần = 4 byte
    uint8_t arr1[11]; // 1 byte
    uint32_t arr2[4]; // 4 byte
    uint16_t arr3[7]; // 2 byte
};
```
### Cách tính số size

uint8_t có size 1 byte => arr1[11] cần 1*11 = 11 byte để lưu, mà 1 lần quét là 4 byte (byte cao nhất trong struct) 

=> arr1[11] = 11 byte + **1 byte dư** = 12 byte (cần 3 lần quét)

uint32_t có size 4 byte => arr2[4] cần 4*4 = 16 byte để lưu 

=>  arr2[4] = 16 byte  (cần 4 lần quét)

uint16_t có size 2 byte => arr3[7] cần 2*7 = 14 byte để lưu

=> arr2[7] = 14 byte + 2 byte dư = 16 byte (cần 4 lần quét)

==> tổng size = 12 byte + 16 byte + 16 byte = 44 byte

## Union  
### Định nghĩa
Cũng giống như struct, union là 1 tập hợp các phần tử dữ liệu cùng kiểu hoặc khác kiểu được gộp chung thành 1 nhóm. Các phần tử này được gọi là thành viên của union.
### Cú pháp
```
union <Tên struct>
{
<Kiểu dữ liệu thành viên số 1> <Tên thành viên số 1>;
<Kiểu dữ liệu thành viên số 2> <Tên thành viên số 2>;
…
};
```
 ```
typedef union
{
    /*size union = size member lớn nhất
      union là bộ nhớ dùng chung nên khi thay đổi member này sẽ ảnh hưởng đến
      member khác.
    */
    uint8_t test1[6]; // 6 byte
    uint8_t test2[2]; // 2 byte
}data_union;
 ```
### Sử dụng Union
- Để truy cập vào các thành viên của union sử dụng toán tử dấu chấm (.) đặt giữa tên biến kiểu union và tên thành viên của union cần truy cập.

- 1 biến thuộc kiểu union cũng có thể trở thành tham số của 1 hàm.

- Có thể truy cập thành viên của union thông qua biến con trỏ.
```
#include <stdio.h>
#include <string.h>
 
/**
 * dinh nghia union Employee
 */
union Employee {
    int id;
    char name[50];
} e1; // khai bao bien e1 cho Employee
 
/**
 * ham main
 */
int main() {
    // luu tru thong tin employee e1
    e1.id = 101;
    strcpy(e1.name, "Vinh Tran"); // chuyen doi chuoi thanh mang char
    // hien thi thong tin e1 ra man hinh
    printf("employee e1 id: %d\n", e1.id);
    printf("employee e1 name: %s\n", e1.name);
    return 0;
}
```
## So sánh Struct - Union
Về mặt ý nghĩa, struct và union cơ bản giống nhau. Tuy nhiên, về mặt lưu trữ trong bộ nhớ, chúng có sự khác biệt rõ rệt như sau:
- Struct: Dữ liệu của các thành viên của struct được lưu trữ ở những vùng nhớ khác nhau. Do đó kích thước của 1 struct tối thiểu bằng kích thước các thành viên cộng lại tại vì còn phụ thuộc vào bộ nhớ đệm (struct padding).
- Union : Dữ liệu các thành viên sẽ dùng chung 1 vùng nhớ. Kích thước của union được tính là kích thước lớn nhất của kiểu dữ liệu trong union. Việc thay đổi nội dung của 1 thành viên sẽ dẫn đến thay đổi nội dung của các thành viên khác.

</details>

<details>
    <summary>EXTERN - STATIC</summary>
    
 ## Extern

 Biến extern được sử dụng khi một tệp cụ thể cần truy cập một biến từ tệp khác.
    
 **VD:**
 ``` 
// file main.c
#include <stdio.h>
extern int count; // sử dụng biến count ở file test
extern void dem(); //sử dụng hàm ở file test
int main ()
{
    printf("count: %d\n",count);
    dem();
    dem();
    return 0; 
   /* Run chương trình : gcc main.c test.c -o main
                        ./main
    Result :   16 
               16
               17 
    */
}
 ```

```
// flie test.c  
int count = 16;

void dem(){
    printf("count = %d\n",count);
    count++;
}
```
 ## Static cục bộ
Khi 1 biến cục bộ được khai báo với từ khóa static. Biến sẽ chỉ được `khởi tạo 1 lần duy nhất` và `tồn tại suốt thời gian chạy chương trình`. `Giá trị của nó không bị mất đi ngay cả kết thúc hàm`. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì `biến cục bộ static chỉ có thể được gọi trong nội bộ hàm khởi tạo ra nó`. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.
```
// Ví dụ
#include <stdio.h>
    
void dem(){
    static int count = 10; // static cục bộ
    printf("count = %d\n",count);
    count++;
}
    
int main()
{
    dem();
    dem();
    dem();
    
    return 0;
}
/*
    Result:
    10
    11
    12
*/
```
## Static toàn cục
Static toàn cục mọi hàm có thể gọi nó được, nhưng nó chỉ có thể được `truy cập và sử dụng trong File khai báo nó, các File khác không có cách nào truy cập được`.
```
 // Ví dụ
 #include <stdio.h>

/*
    static toàn cục chỉ có thể lấy giá trị trong file chứa nó
    nên khi sử dụng extern để sử dụng biến, hàm đó ở file khác sẽ báo lỗi
*/

static int count = 16;

void dem(){
    printf("count = %d\n",count);
    count++;
}
int main()
{
    dem();
    dem();
}
/*
    Result: 
    16
    17
*/
```
</details>
    
<details>
<summary>POINTER</summary>
 
## Null Pointer
- Con trỏ null là con trỏ có giá trị và địa chỉ bằng 0.
- Khi khai báo 1 con trỏ:
    + Phải khai báo địa chỉ cho nó.
    + Nếu mà chưa sử dụng thì gán cho nó con trỏ null. 
    + Hoặc khi khai báo con trỏ và đã sử dụng nó rồi, khi không muốn sử dụng nó nữa thì phải gán nó lại là con trỏ null.
```
    int *ptr = NULL;
```
## Function Pointer
- Sau khi khai báo thì hàm cũng được lưu trữ tại một địa chỉ trong bộ nhớ, và do đó, chúng ta cũng có thể sử dụng con trỏ để lưu trữ địa chỉ và qua đó thao tác với chúng.
- Chúng ta gọi con trỏ lưu trữ địa chỉ của một hàm là con trỏ hàm trong c, và sử dụng nó để truy cập vào địa chỉ của hàm, cũng như thực thi các xử lý bên trong hàm đó.
 ```
    Cách khai báo:
        type (*fp) ( para_type_1, para_type_2, para_type_3,...);
    fp: tên con trỏ hàm.
    type: kiểu của con trỏ.
    para_type_1,.. : các kiểu của các đối số parameter.
 ```
 ```
 VD:
#include <stdio.h>

void tong(int a,int b){
    printf("tong %d va %d = %d\n", a, b, a + b);
}

void hieu(int a,int b){
    printf("hieu %d va %d = %d\n", a, b, a - b);
}

void tich(int a,int b){
    printf("tich %d va %d = %d\n", a, b, a * b);
}

void thuong(int a,int b){
    printf("thuong %d va %d = %f\n", a, b, (float)a/b);
}

void tinhtoan(int a, int b, void (*ptr)(int, int))
{   // thông qua con trỏ hàm để hàm làm input parameter
    printf("Chuong trin tinh toan\n");
    ptr(a,b);
}
int main()
{

    // void (*pheptoan)(int, int) = NULL;
    // pheptoan = thuong;
    // pheptoan(5,1);

    tinhtoan(8,6,thuong);
    return 0;
}
    
 ```
 ## Void Pointer
 - `Con trỏ void có thể trỏ đến các vùng nhớ có các kiểu dữ liệu khác nhau`.
 - Tuy nhiên, con trỏ void không xác định được kiểu dữ liệu của vùng nhớ mà nó trỏ tới, vì vậy không thể truy cập xuất trực tiếp nội dung thông qua toán tử derefernce () được. Mà `con trỏ kiểu void` cần `phải được ép kiểu` một cách rõ ràng `sang con trỏ có kiểu dữ liệu khác trước khi sử dụng toán tử derefernce` ().
 ```
 #include <stdio.h>

void tong(int a,int b){
    printf("tong %d va %d = %d\n", a, b, a + b);
}

int main()
{

    int i = 3;
    double d =12.4;
    char c ='B';

    // con trỏ void có thể trỏ đến bất kỳ địa chỉ nào 
    void *ptr = &i;

    // để lấy giá trị từ con trỏ void ta cần ép kiểu nó
    printf("i = %d\n",*(int *)ptr);

    ptr = &d;
    printf("d = %f\n",*(double *)ptr);

    ptr = &c;
    printf("c = %c\n",*(char *)ptr);

    ptr = &tong;
    ((void (*)(int, int))ptr)(9,1);
    return 0;
}
    
 ```
 ## Pointer to Pointer
 Con trỏ trỏ đến con trỏ (Pointers to pointers) là một con trỏ chứa địa chỉ của một con trỏ khác.
    
 ```
  cách khai báo: 
   data_type_of_pointer **name_of_variable = & normal_pointer_variable;
 ```
 
 ```
int val = 5; 
int *ptr = &val; // lưu địa chỉ của val vào con trỏ ptr. 
int **d_ptr = &ptr; // con trỏ tới một con trỏ được khai báo 
                    // đang trỏ tới một số nguyên.
    
 ```
 ```
 VD :
 #include <stdio.h>
 
int main()
{
    int var = 123;
 
    int* ptr2;
 
    int** ptr1;
 
    ptr2 = &var;
 
    ptr1 = &ptr2;
 
    printf("Gia tri var = %d\n", var);
    printf("Gia tri *pointer = %d\n", *ptr2);
    printf("Gia tri **pointer = %d\n", **ptr1);
 
    return 0;
    
    /*
     Result : 
        Gia tri var = 123
        Gia tri *pointer = 123
        Gia tri **pointer = 123
    */
}
 ```
</details>
<details>
<summary>CONSTRUCTOR</summary>

# Định nghĩa
	
`Constructor` trong C++ là một phương thức đặc biệt được gọi tự động tại thời điểm tạo đối tượng. Nó được sử dụng để khởi tạo các thành viên dữ liệu của các đối tượng mới. Constructor trong C++ có cùng tên với lớp hoặc struct.

Constructor trong C++ có thể được chia thành 2 loại:

- `Constructor mặc định`.
- `Constructor có tham số`.
  
# Constructor mặc định

Một `constructor không có đối số` được gọi là `constructor mặc định`. Nó được gọi tại thời điểm tạo đối tượng.

Ví dụ về Constructor mặc định trong C++:

```
#include <iostream>
 
using namespace std;
 
class Employee {
public:
    Employee() {
        cout << "Constructor mac dinh duoc goi..." << endl;
    }
};
 
int main(void) {
    Employee e1; //tao doi tuong Employee
    Employee e2;
    return 0;
}
```
Kết quả :

Constructor mac dinh duoc goi...
Constructor mac dinh duoc goi...

# Constructor có tham số

Một constructor có tham số được gọi là constructor tham số hóa. Nó được sử dụng để cung cấp các giá trị khác nhau cho các đối tượng riêng biệt.

Ví dụ về Constructor tham số trong C++:

```
#include <iostream>
 
using namespace std;
 
class Employee {
public:
    int id; // data member (bien instance)
    string name; // data member(bien instance)
    float salary;
    Employee(int i, string n, float s)
    {
        id = i;
        name = n;
        salary = s;
    }
    void display() { cout << id << "  " << name << "  " << salary << endl; }
};
 
int main(void) {
    Employee e1 = Employee(101, "Phan Van Vinh", 500); // tao doi tuong Employee
    Employee e2 = Employee(102, "Dao Van Hoa", 1000);
    e1.display();
    e2.display();
    return 0;
}

Kết quả :
101  Phan Van Vinh  500
102  Dao Van Hoa  1000
```

# Khi nào sử dụng Constructor ?

`Constructor` được sử dụng khi bạn tạo một đối tượng mới của một lớp. Nó được gọi tự động khi khởi tạo một đối tượng và thường được sử dụng để thiết lập các giá trị ban đầu của đối tượng.

Một số trường hợp bạn có thể sử dụng constructor bao gồm:

1.Khởi tạo các biến thành viên của lớp.
2.Thực hiện các thao tác khởi tạo phức tạp như kết nối đến cơ sở dữ liệu.
3.Thiết lập các giá trị mặc định cho các thuộc tính của đối tượng.
4.Thiết lập các tham số cần thiết để tạo ra một đối tượng hợp lệ.
Constructor có thể nhận các tham số và sử dụng chúng để thiết lập giá trị ban đầu của đối tượng. Bạn cũng có thể tạo nhiều hơn một constructor trong cùng một lớp, được gọi là `constructor overloading`, để hỗ trợ việc khởi tạo theo nhiều cách khác nhau.

Về cú pháp, constructor có cùng tên với lớp và không có kiểu trả về. Điều này cho phép chúng được gọi tự động khi một đối tượng mới được tạo.

Ví dụ :
```
public class Circle {
    private double radius;

    // Constructor không tham số
    public Circle() {
        this.radius = 1.0;
    }

    // Constructor nhận tham số
    public Circle(double radius) {
        this.radius = radius;
    }

    // ...
}

```
</details>
<details>
<summary>CLASS C++</summary>
	
## Class là gì?
	
`Class` hay lớp là một mô tả `trừu tượng (abstract)` của nhóm các `đối tượng (object)` có 
cùng bản chất, ngược lại mỗi một đối tượng là một `thể hiện cụ thể (instance)` cho những mô tả trừu tượng đó. Một class trong C++ sẽ có các đặc điểm sau:
- Một class bao gồm các thành phần dữ liệu (thuộc tính hay property) và các 
phương thức (hàm thành phần hay method).
- Class thực chất là một kiểu dữ liệu do người lập trình định nghĩa.
- Trong C++, từ khóa class sẽ chỉ điểm bắt đầu của một class sẽ được cài đặt. 
Ví dụ về một class đơn giản, class Car. Một chiếc xe hơi vậy thì sẽ có chung những đặc điểm là đều có vô lăng, có bánh xe nhiều hơn 3, có động cơ… Đó là một class, một cái model hay mẫu mà người ta đã quy định là nếu đúng như vậy thì nó là xe hơi. Nhưng mà xe thì có thể có nhiều hãng khác nhau, BMW, Vinfast, Toyota… Thì mỗi hãng xe lại có những model xe khác nhau nhưng chúng đều là xe hơi. Vậy thì trong lập trình cũng vậy, class là quy định ra một mẫu, một cái model mà các thể hiện của nó (instance) hay đối tượng (object) phải tuân theo.

## Khai báo class và sử dụng class

Ví dụ một class cơ bản:
```
class Person {
 public:
 string firstName; // property
 string lastName; // property
 int age; // property
 void fullname() { // method
 cout << firstName << ' ' << lastName;
 }
};
```
Cú pháp tạo object của một class và sử dụng các thuộc tính và phương thức:
```
Person person;
person.firstName = "Khiem";
person.lastName = "Le";
person.fullname(); // sẽ in ra màn hình là "Khiem Le"
```

</details>

<details>
<summary>PHẠM VI TRUY CẬP</summary>

## Access modifiers & properties declaration

`Access modifier` là phạm vi truy cập của các `thuộc tính` và `phương thức` sẽ được khai báo bên dưới nó. Có 3 phạm vi truy cập trong C++ là `public`, `private` và `protected`.
- Các thuộc tính và phương thức khai báo public thì có thể được truy cập trực tiếp thông qua `instance` của class đó. Các thuộc tính nên khai báo là `public` 
nếu bạn không có ràng buộc điều kiện trước khi gán (người dùng có thể thoải mái gán giá trị) hoặc bạn không cần xử lý trước khi trả về giá trị thuộc 
tính;
- Các thuộc tính `private` thường được sử dụng khi bạn không mong muốn người khác có thể tùy ý gán giá trị hoặc là bạn muốn xử lý trước khi trả về 
giá trị.
- Đối với `protected`, các phương thức và thuộc tính chỉ có thể truy cập qua các class kế thừa nó hoặc chính nó.

Ví dụ của access modifier:
```
class MyClass
{
public:
int public_property;
private:
int _private_property;
};
```
## Method declaration

Phương thức cũng giống như một hàm bình thường.
Đối với phương thức thì có hai cách định nghĩa thi hành: định nghĩa thi hành trong lúc định nghĩa class và định nghĩa thi hành bên ngoài class.
Định nghĩa thi hành bên trong class:
```
class Animal {
 public:
 string sound;
 void makeNoise() {
 cout << sound;
 }
};
```
Định nghĩa thi hành bên ngoài class:
```
class Animal {
 public:
 string sound;
 void makeNoise();
};
void Animal::makeNoise() {
 cout << sound;
}
```

## Constructor

`Constructor` hay hàm dựng là một hàm đặc biệt, nó sẽ được gọi ngay khi chúng ta khởi tạo một `object`. 
```
class Person {
public:
 string firstName;
 string lastName;
 int age;
Person(string _firstName, string _lastName, int _age)
 {
 firstName = _firstName;
 lastName = _lastName;
 age = _age;
 }
 void fullname() {
cout << firstName << ' ' << lastName;
 }
};
```

## Static member

`Static member` hay `thành viên tĩnh` trong class C++ cũng tương tự như với `static variable (biến tĩnh)` trong function. Đối với function, sau khi thực hiện xong khối lệnh và thoát thì biến tĩnh vẫn sẽ không mất đi. Đối với class, thành viên tĩnh sẽ là thuộc tính dùng chung cho tất cả các đối tượng của class đó, cho dù là không có đối tượng nào tồn tại. Tức là bạn có thể khai báo nhiều object, mỗi object các thuộc tính của nó đều khác nhau nhưng riêng static thì chỉ có một và static member tồn tại trong suốt chương trình cho dù có hay không có object nào của nó hay nói ngắn gọn là 
dùng chung một biến static.

</details>

<details>
<summary>ĐẶC TÍNH CỦA HƯỚNG ĐỐI TƯỢNG</summary>
	
Có 4 đặc tính quan trọng của lập trình hướng đối tượng trong C++ mà chúng ta cần 
nắm vững sau đây.

`Inheritance (Tính kế thừa )` trong lập trình hướng đối tượng có ý nghĩa, một class 
có thể kế thừa các thuộc tính của một class khác đã tồn tại trước đó.

Khi một class con được tạo ra bởi việc kế thừa thuộc tính của class cha thì chúng ta 
sẽ gọi class con đó là subclass trong C++, và class cha chính là superclass trong 
C++.


`Abstraction (Tính trừu tượng)` trong lập trình hướng đối tượng là một khả năng 
mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông 
tin cần xử lý.
Điều đó có nghĩa, bạn có thể xử lý một đối tượng bằng cách gọi tên một phương 
thức và thu về kết quả xử lý, mà không cần biết làm cách nào đối tượng đó được các 
thao tác trong class.

Ví dụ đơn giản, bạn có thể nấu cơm bằng nồi cơm điện bằng cách rất đơn giản là ấn 
công tắc nấu, mà không cần biết là bên trong cái nồi cơm điện đó đã làm thế nào mà 
gạo có thể nấu thành cơm.


`Polymorphism (Tính đa hình)` trong lập trình hướng đối tượng là một khả năng mà 
một phương thức trong class có thể đưa ra các kết quả hoàn toàn khác nhau, tùy 
thuộc vào dữ liệu được xử lý.

Ví dụ đơn giản, cùng là một class quản lý dữ liệu là các con vật, thì hành động sủa 
hay kêu của chúng được định nghĩa trong class sẽ cho ra kết quả khác nhau, ví dụ 
nếu là con mèo thì kêu meo meo, còn con chó thì sủa gâu gâu chẳng hạn.


`Encapsulation (Tính đóng gói)` trong lập trình hướng đối tượng có ý nghĩa không 
cho phép người sử dụng các đối tượng thay đổi trạng thái nội tại của một đối tượng, 
mà chỉ có phương thức nội tại của đối tượng có thể thay đổi chính nó.

Điều đó có nghĩa, dữ liệu và thông tin sẽ được đóng gói lại, giúp các tác động bên 
ngoài một đối tượng không thể làm thay đổi đối tượng đó, nên sẽ đảm bảo tính toàn 
vẹn của đối tượng, cũng như giúp dấu đi các dữ liệu thông tin cần được che giấu.

Ví dụ đơn giản, khi bạn dùng một cái iphone, bạn không thể thay đổi các cấu trúc 
bên trong của hệ điều hành iOS, mà chỉ có Apple mới có thể làm được điều này thôi.

</details>

<details>
<summary>NAMESPACE & TEMPLATE </summary>

### NAMEPSPACE

## Tình huống

Khi đang lập trình trong một file A bạn include 2 file B và C, nhưng 2 file này có cùng định nghĩa một hàm function() giống nhau về tên và tham số truyền vào, nhưng xử lý của mỗi hàm ở mỗi file là khác nhau, vấn đề đặt ra là code làm sao để trình biên dịch hiểu được khi nào bạn muốn gọi function của file B, khi nào bạn muốn gọi function của file C. Khi gọi hàm function() ở file A, trình biên dịch sẽ không biết được hàm function() bạn muốn gọi là hàm được định nghĩa ở file B hay file C. Vì vậy trình biên dịch chương trình sẽ báo lỗi.

## Định nghĩa:

`Namespace` là từ khóa trong C++ được sử dụng để định nghĩa một phạm vi nhằm mục đích phân biệt các hàm, lớp, biến, ... cùng tên trong các thư viện khác nhau.

## Cú pháp
```
namespace ten_namespace{
    //code
}
```

fileB.hpp:
```
#include <iostream>

using namespace std;

namespace fileB{
    void function(() { cout << “function in fileB running.” << endl; }
}
```
fileC.hpp:
```
#include <iostream>

using namespace std;

namespace fileC{
    void function(() { cout << “function in fileC running.” endl; }
}
```
fileA.hpp:
```
#include <iostream>
#incldue “fileB.hpp”
#include “fileC.hpp”

using namespace std;

int main() {
    fileB::function();
    fileC::function();
    
    return 0;
}
```
Kết quả:
```
function fileB running.
function fileC running.
```

### TEMPLATE

- Template (khuôn mẫu) là một từ khóa trong C++, và là một kiểu dữ liệu trừu tượng tổng quát hóa cho các kiểu dữ liệu int, float, double, bool...
- Template trong C++ có 2 loại đó là function template & class template.
- Template giúp người lập trình định nghĩa tổng quát cho hàm và lớp thay vì phải nạp chồng (overloading) cho từng hàm hay phương thức với những kiểu dữ liệu khác nhau.

</details>

<details>
<summary>VECTOR</summary>

Giống như là mảng (array), vector trong C++ là một đối tượng dùng để chứa các đối tượng khác, và các đối tượng được chứa này cũng được lưu trữ một cách liên tiếp 
trong vector.
Tuy nhiên, nếu như số lượng phần tử (size) của một mảng là cố định, thì ở vector, nó hoàn toàn có thể thay đổi trong suốt quá trình làm việc của chương trình

## Modifiers

1. `push_back()`: Hàm đẩy một phần tử vào vị trí sau cùng của vector. Nếu kiểu của đối tượng được truyền dưới dạng tham số trong push_back() không giống với kiểu 
của vector thì sẽ bị ném ra.

`ten-vector.push_back(ten-cua-phan-tu);`

2. assign(): Nó gán một giá trị mới cho các phần tử vector bằng cách thay thế các giá trị cũ.
   
`ten-vector.assign(int size, int value);`

3. `pop_back()`: Hàm pop_back () được sử dụng để xóa đi phần tử cuối cùng mộtvector.

4. `insert()`: Hàm này chèn các phần tử mới vào trước phần tử trước vị trí được trỏ bởi vòng lặp. Chúng ta cũng có thể chuyển một số đối số thứ ba, đếm số lần phần tử được chèn vào trước vị trí được trỏ.
   
5. `erase()`: Hàm được sử dụng để xóa các phần tử tùy theo vị trí vùng chứa
  
6. `emplace()`: Nó mở rộng vùng chứa bằng cách chèn phần tử mới vào
    
7.`emplace_back()`: Nó được sử dụng để chèn một phần tử mới vào vùng chứa vector, phần tử mới sẽ được thêm vào cuối vector

8. `swap()`: Hàm được sử dụng để hoán đổi nội dung của một vector này với một vector khác cùng kiểu. Kích thước có thể khác nhau.
    
9.`clear()`: Hàm được sử dụng để loại bỏ tất cả các phần tử của vùng chứa vector
 
</details>

<details>
<summary>LIST</summary>
	
Trong C++,`list` là một container trong STL (Standard Template Library) dùng để lưu trữ và quản lý các phần tử liên tục. Nó có thể chứa các kiểu dữ liệu khác nhau và cung cấp các hàm tiên tiến để thao tác với các phần tử trong list.

Cú pháp khai báo:
```
list<T> variable_name;
```
Trong đó, T là kiểu dữ liệu của các phần tử trong list.

Ví dụ:
```
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> numbers;
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(8);
    numbers.push_back(1);

    cout << "Elements of the list: ";
    for (auto i : numbers) {
        cout << i << " ";
    }
    cout << endl;

    numbers.sort();
    cout << "Sorted list: ";
    for (auto i : numbers) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

Kết quả:
Elements of the list: 5 3 8 1
Sorted list: 1 3 5 8
```
# Một số ví dụ 

Ví dụ 1: Tạo và thêm phần tử vào list:
```
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> numbers;
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(8);
    numbers.push_back(1);

    cout << "Elements of the list: ";
    for (auto i : numbers) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
```

Ví dụ 2: Xóa phần tử từ list
```
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> numbers;
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(8);
    numbers.push_back(1);

    cout << "Elements of the list before deletion: ";
    for (auto i : numbers) {
        cout << i << " ";
    }
    cout << endl;

    // Xóa phần tử có giá trị 3 từ list
    numbers.remove(3);

    cout << "Elements of the list after deletion: ";
    for (auto i : numbers) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
```
Ví dụ 3: Sắp xếp và in ra list:
```
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> numbers;
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(8);
    numbers.push_back(1);

    cout << "Elements of the list before sorting: ";
    for (auto i : numbers) {
        cout << i << " ";
    }
    cout << endl;

    numbers.sort();

    cout << "Elements of the list after sorting: ";
    for (auto i : numbers) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
```

# Các phương thức phổ biến 

Các phương thức phổ biến của list bao gồm:

- push_back(value): Thêm phần tử vào cuối danh sách.
- push_front(value): Thêm phần tử vào đầu danh sách.
- pop_back(): Xóa phần tử cuối cùng khỏi danh sách.
- pop_front(): Xóa phần tử đầu tiên khỏi danh sách.
- insert(position, value): Thêm phần tử vào danh sách tại vị trí được chỉ định.
- erase(position): Xóa phần tử tại vị trí được chỉ định khỏi danh sách.
- size(): Trả về số lượng phần tử trong danh sách.
- begin(): Trả về một con trỏ đến phần tử đầu tiên trong danh sách.
- end(): Trả về một con trỏ đến phần tử cuối cùng trong danh sách.


</details>

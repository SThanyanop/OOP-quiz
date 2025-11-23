# ระบบจัดการร้านกาแฟ - Coffee Shop Management System
### 📝Question
สร้างระบบจัดการร้านกาแฟโดยใช้หลักการ OOP ที่ประกอบด้วย:
- มีเครื่องดื่ม 3 ประเภท (กาแฟ, ชา, น้ำผลไม้) 
- แต่ละเครื่องดื่มมีขนาด S, M, L ที่ราคาต่างกัน
- คำนวณราคารวมของออเดอร์
- คืนค่ารายละเอียดออเดอร์ (ไม่ใช่การ print)

## 📊 Price Table
| Beverage   | Base Price | Size S (-20%) | Size M (100%) | Size L (+30%) |
| ---------- | ---------- | ------------- | ------------- | ------------- |
| **Coffee** | 50 baht    | 40 baht       | 50 baht       | 65 baht       |
| **Tea**    | 35 baht    | 28 baht       | 35 baht       | 45.5 baht     |
| **Juice**  | 40 baht    | 32 baht       | 40 baht       | 52 baht       |

## 📥Input(s)
### Input Parameters:
1. coffee_size: char ('S', 'M', 'L')
2. add_milk: boolean (true/false)
3. tea_size: char ('S', 'M', 'L')
4. juice_fruit: string ("Orange", "Apple", "Mango", etc.)
5. juice_size: char ('S', 'M', 'L')
## 📤Output(s)
### Return Values (ค่าที่ต้องคืนจากฟังก์ชัน):

1. coffee_price: double
   - คำนวณจาก: (base_price + milk_cost) * size_multiplier
   - base_price = 50
   - milk_cost = 10 (ถ้า add_milk = true)
   - size_multiplier = 0.8 (S), 1.0 (M), 1.3 (L)

2. tea_price: double  
   - คำนวณจาก: base_price * size_multiplier
   - base_price = 35
   - size_multiplier = 0.8 (S), 1.0 (M), 1.3 (L)

3. juice_price: double
   - คำนวณจาก: base_price * size_multiplier
   - base_price = 40
   - size_multiplier = 0.8 (S), 1.0 (M), 1.3 (L)

4. total_price: double
   - คำนวณจาก: coffee_price + tea_price + juice_price

5. order_details: struct containing all information
## ⚙️Function

## 💡 Example

Input Function Call
```cpp
OrderSummary result = processOrder('L', true, 'M', "Orange", 'S');
PriceBreakdown prices = calculatePrices('L', true, 'M', "Orange", 'S');
```
Expected Return Values

```cpp
result.items[0] = {"Coffee with Milk", 'L', 78.0}
result.items[1] = {"Tea", 'M', 35.0}
result.items[2] = {"Orange Juice", 'S', 32.0}
result.total_price = 145.0

prices.coffee_price = 78.0   // (50 + 10) * 1.3
prices.tea_price = 35.0       // 35 * 1.0
prices.juice_price = 32.0     // 40 * 0.8
prices.total = 145.0
```

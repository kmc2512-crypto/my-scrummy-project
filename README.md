# my-scrummy-project
# プロジェクト名
『♡ あるこーる ダメ！ ゼッタイ ♡』

## これは何？
酒気帯び検査をします。
引っ掛かったら音が鳴ってビンタされます。
ボタンを押すと"なぜか"引っかかります。

## 動作内容
- アルコールセンサーでアルコールを測る
- センサーに反応/ボタンを押すとサーボでビンタする

## 使い方
スクーミーのプロジェクトを開いて実行する→人から
無理やり引っ掛けたい場合はボタンを押すと可能
（スクーミーのプロジェクトを開いて実行する、など）

## コード
```  #include <SchooMyUtilities.h>
#include <Servo.h>
SchooMyUtilities scmUtils = SchooMyUtilities();

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(A5, INPUT);
  pinMode(15, INPUT);
  myServo.attach(9); // 右下ポートのfirstピン
  myServo.write(0);
}

void loop() {
  int alcoholVal = analogRead(A5);
  Serial.println(alcoholVal);

  if ((!digitalRead(15) == 1) || (alcoholVal > 300)) {
    // ビビッ警告音
    tone(5, SchooMyUtilities::F_E3, 100);
    delay(150);
    noTone(5);
    tone(5, SchooMyUtilities::F_E3, 100);
    delay(150);
    noTone(5);

    // サーボでビンタ
    myServo.write(90);
    delay(500);
    myServo.write(0);
    delay(500);
  }
} ```

## 作った人
折原悠太、角倉知采、後上彰吾、野口竜之介 / 2026年 基礎プログラミングII

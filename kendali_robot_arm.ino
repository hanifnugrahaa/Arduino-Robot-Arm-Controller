#include <Servo.h>

/**
 * Arduino Robot Arm Controller
 * 
 * Program untuk mengendalikan robot arm dengan 4 DOF:
 * - YAW: Pergerakan rotasi horizontal
 * - DOF1: Joint pertama (depan/belakang)
 * - DOF2: Joint kedua (naik/turun)
 * - CLAW: Pencapit (buka/tutup)
 * 
 * Cheat Code:
 * 5146752246753046760 --flexing mode
 * 1569 -- demo
 */

// Deklarasi servo
Servo yaw;   // Servo untuk rotasi basis (kiri-kanan)
Servo dof1;  // Servo untuk joint pertama
Servo dof2;  // Servo untuk joint kedua
Servo claw;  // Servo untuk pencapit

// Variabel dan parameter
char option;           // Menyimpan perintah yang diterima
int angle_yaw = 90;    // Posisi awal servo YAW (0-180 derajat)
int angle_dof1 = 50;   // Posisi awal servo DOF1 (0-180 derajat)
int angle_dof2 = 130;  // Posisi awal servo DOF2 (0-180 derajat)
int angle_claw = 0;    // Posisi awal servo CLAW (0-30 derajat)

/**
 * Menampilkan daftar perintah yang tersedia ke Serial Monitor
 */
void print_command() {
  Serial.println("Command list");
  Serial.println("1. yaw left");
  Serial.println("2. yaw right");
  Serial.println("3. yaw normal");
  Serial.println("4. dof1 back");
  Serial.println("5. dof1 normal");
  Serial.println("6. dof2 down");
  Serial.println("7. dof2 normal");
  Serial.println("8. claw open");
  Serial.println("9. claw close");
  Serial.println("10. Calibrate");
}

/**
 * Inisialisasi program
 */
void setup() {
  // Konfigurasi pin servo
  yaw.attach(6);
  dof1.attach(9);
  dof2.attach(10);
  claw.attach(11);

  // Set posisi awal servo
  yaw.write(angle_yaw);
  dof1.write(angle_dof1);
  dof2.write(angle_dof2);
  claw.write(angle_claw);

  // Inisialisasi komunikasi serial
  Serial.begin(9600);
  print_command();
  Serial.println("Arm ready");
}

/**
 * Loop utama program
 */
void loop() {
  // Memeriksa apakah ada data yang diterima dari Serial
  if (Serial.available()) {
    option = Serial.read();
    
    // Eksekusi perintah sesuai dengan karakter yang diterima
    switch (option) {
      case '1': // Menggerakkan YAW ke kiri
        if (angle_yaw < 180) {
          angle_yaw += 90;
          yaw.write(angle_yaw);
          Serial.println("Yaw moved right");
        } else {
          Serial.println("Already at maximum value");
        }
        delay(500);
        break;

      case '2': // Menggerakkan YAW ke kanan
        if (angle_yaw > 0) {
          angle_yaw -= 90;
          yaw.write(angle_yaw);
          Serial.println("Yaw moved left");
        } else {
          Serial.println("Already at minimum value");
        }
        delay(500);
        break;

      case '3': // Mengembalikan YAW ke posisi normal
        angle_yaw = 90;
        yaw.write(angle_yaw);
        Serial.println("Yaw reset to normal");
        delay(500);
        break;

      case '4': // Menggerakkan DOF1 ke belakang
        dof1.write(50);
        Serial.println("DOF 1 back");
        delay(500);
        break;

      case '5': // Mengembalikan DOF1 ke posisi normal
        dof1.write(120);
        Serial.println("DOF 1 normal");
        delay(500);
        break;

      case '6': // Menurunkan DOF2
        dof2.write(50);
        Serial.println("DOF 2 turun");
        delay(500);
        break;

      case '7': // Mengembalikan DOF2 ke posisi normal
        dof2.write(130);
        Serial.println("DOF 2 normal");
        delay(500);
        break;

      case '8': // Membuka pencapit
        claw.write(30);
        Serial.println("Claw opened");
        delay(500);
        break;

      case '9': // Menutup pencapit
        claw.write(0);
        Serial.println("Claw closed");
        delay(500);
        break;

      case '0': // Kalibrasi semua servo ke posisi default
        angle_yaw = 90;
        angle_dof1 = 50;
        angle_dof2 = 130;
        angle_claw = 0;
        yaw.write(angle_yaw);
        dof1.write(angle_dof1);
        dof2.write(angle_dof2);
        claw.write(angle_claw);
        Serial.println("Calibrated to default positions");
        delay(500);
        break;  
        
      default:
        delay(500);
        break;
    }
  }
}

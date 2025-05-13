# Deskripsi
Program ini mengendalikan robot arm dengan 4 servo motor untuk menggerakkan basis (yaw), 
joint pertama (dof1), joint kedua (dof2), dan pencapit (claw). Program menerima perintah 
melalui komunikasi serial dari komputer untuk mengatur posisi masing-masing servo.

# Pin Arduino
- Servo YAW: Pin 6
- Servo DOF1: Pin 9
- Servo DOF2: Pin 10
- Servo CLAW: Pin 11

# Komunikasi Serial
- Baudrate: 9600
- Perintah: Single character (1-9, 0)

# Perintah Tersedia
1. Menggerakkan YAW ke kiri (+90 derajat)
2. Menggerakkan YAW ke kanan (-90 derajat)
3. Mengembalikan YAW ke posisi normal (90 derajat)
4. Menggerakkan DOF1 ke belakang (50 derajat)
5. Menggerakkan DOF1 ke posisi normal (120 derajat)
6. Menurunkan DOF2 (50 derajat)
7. Mengembalikan DOF2 ke posisi normal (130 derajat)
8. Membuka CLAW (30 derajat)
9. Menutup CLAW (0 derajat)
0. Kalibrasi semua servo ke posisi default

# Posisi Default
- YAW: 90 derajat
- DOF1: 50 derajat
- DOF2: 130 derajat
- CLAW: 0 derajat (tertutup)

# Kode Rahasia
- 5146752246753046760: Mode flexing
- 1569: Mode demo

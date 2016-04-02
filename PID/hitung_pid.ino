void hitung_pid() {
  P = error;
  I = (I + error);
  D = (error - error_sebelumnya);

  PID = ((Kp * P) + (Ki * I) + (Kd * D));

  error_sebelumnya = error;
}

#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include <webots/Motor.hpp>

#define TIME_STEP 64

using namespace webots;

int main(int argc, char **argv) {
  // Inicializar la instancia del Robot
  Robot *robot = new Robot();

  // Obtener y habilitar los 8 sensores de distancia (ps0 a ps7)
  DistanceSensor *ps[8];
  char psNames[8][4] = {
    "ps0", "ps1", "ps2", "ps3",
    "ps4", "ps5", "ps6", "ps7"
  };

  for (int i = 0; i < 8; i++) {
    ps[i] = robot->getDistanceSensor(psNames[i]);
    ps[i]->enable(TIME_STEP);
  }

  // Configurar los motores de las ruedas
  Motor *leftMotor = robot->getMotor("left wheel motor");
  Motor *rightMotor = robot->getMotor("right wheel motor");
  leftMotor->setPosition(INFINITY);
  rightMotor->setPosition(INFINITY);
  leftMotor->setVelocity(0.0);
  rightMotor->setVelocity(0.0);

  // Bucle principal de control (feedback loop)
  while (robot->step(TIME_STEP) != -1) {
    // 1. Leer sensores
    double psValues[8];
    for (int i = 0; i < 8; i++) {
      psValues[i] = ps[i]->getValue();
    }

    // 2. Procesar comportamiento (detectar obstáculos a los lados/frente)
    bool right_obstacle = psValues[0] > 80.0 || psValues[1] > 80.0 || psValues[2] > 80.0;
    bool left_obstacle  = psValues[5] > 80.0 || psValues[6] > 80.0 || psValues[7] > 80.0;

    // Velocidad base
    double leftSpeed  = 0.5 * 6.28;
    double rightSpeed = 0.5 * 6.28;

    // Girar si hay un obstáculo
    if (left_obstacle) {
      leftSpeed  += 0.5 * 6.28;
      rightSpeed -= 0.5 * 6.28;
    } else if (right_obstacle) {
      leftSpeed  -= 0.5 * 6.28;
      rightSpeed += 0.5 * 6.28;
    }

    // 3. Aplicar velocidades a los motores
    leftMotor->setVelocity(leftSpeed);
    rightMotor->setVelocity(rightSpeed);
  }

  delete robot;
  return 0;
}

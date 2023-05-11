#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <math.h>
#include <inttypes.h>

class Actuator {
private:
    static uint8_t ID_counter;
    uint8_t ID; 
    double current_pos = NAN;
    double target_pos = NAN;
    double expected_pos = NAN;
    double limits[2] = {NAN, NAN};

public:
/**
 * @brief Objeto base para trabajar con los actuadores.
 * A cada uno se le asigna un identificador, que por ejemplo se retorna en caso de error.
 */
    Actuator() {
        if (!ID_counter) ID = ID_counter = 1;
        else if (ID_counter < UINT8_MAX and ID_counter) ID = ID_counter <<= 1;
        else ID = 0;
    }
    uint8_t get_id() { return ID; }
    int set_target(double target);
    double get_target() { return target_pos; }
    void set_limits(double lim1, double lim2);
    void get_limits(double& lim1, double& lim2) { lim1 = limits[0]; lim2 = limits[1]; }
    /**
     * @brief Mueve el motor. Debe llamarse cíclicamente y calcula posición,
     * errores y hace seguimiento del estado.
     * @return Si hay error, el ID del motor
     */
    virtual int move();
    /** @brief Parada rápida del motor por seguridad
     */
    virtual void emergency_stop();
    /** @brief Implementa lectura de la posición actual, actualiza atributos
     */
    virtual double get_current_pos();
    /** @brief Verifica que todo está OK. Eso incluye que no aumente
     * significativamente el error en el tiempo
    */
    void watchdog();
};

#endif // ACTUATOR_H

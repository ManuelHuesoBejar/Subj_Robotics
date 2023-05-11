#pragma once

#include "nodes.hpp"
#include "poses.hpp"

namespace kinetics
{
    /** @brief Calcula las coordenadas del efector de Alice
     * @arg in : coordenadas articulares
     * @arg out : coordenadas espaciales
     * @returns int : 0 si no hay error, no-nulo si lo hay
    */
    int
    alice_direct(const Pose& in, Node& out);

    /** @brief Calcula las coordenadas articulares para determinada posición del efector
     * @details Devuelve las coordenadas más próximas a la actual, siempre que sea alcanzable
     * @arg in : coordenadas espaciales del efector
     * @arg current : coordenadas actuales de Alice (el robot)
     * @arg out : coordenadas articulares correspondientes
     * @returns int : 0 si no hay error, no-nulo si lo hay
    */
    int
    alice_inverse(const Node& in, const Pose& current, Pose& out);
    
} // namespace kinetics

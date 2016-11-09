#include "Torso.h"

Torso::Torso(double price, int SKU, string name) : Part(TORSO, price, SKU, name) {}

int Torso::getBatterySlots() {return battery_slots;}
void Torso::setBatterySlots(int n) {battery_slots = n;}

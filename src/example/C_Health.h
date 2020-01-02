//
// Created by thekatze on 02/01/2020.
//

#ifndef SHVRD_C_HEALTH_H
#define SHVRD_C_HEALTH_H

#include <components/Component.h>

class C_Health : public Component {
    unsigned int m_health, m_maxHealth;
public:
    C_Health(unsigned int health, unsigned int maxHealth)
        : m_health(health)
        , m_maxHealth(maxHealth) {}

    explicit C_Health(unsigned int health) : C_Health(health, health) {}

    ~C_Health() = default;

    bool isDead() {
        return m_health == 0;
    }

    bool isFullHealth() {
        return m_health == m_maxHealth;
    }

    float getHealthPercentage() {
        return (float) m_health / (float) m_maxHealth;
    }

    unsigned int getHealth() {
        return m_health;
    }

    unsigned int getMaxHealth() {
        return m_maxHealth;
    }

    void setHealth(unsigned int health) {
        if (health > m_maxHealth) {
            health = m_maxHealth;
        }

        m_health = health;
    }

    void setMaxHealth(unsigned int maxHealth) {
        if (maxHealth < m_health) {
            m_health = maxHealth;
        }

        m_maxHealth = maxHealth;
    }

    void applyDamage(unsigned int damage) {
        if (damage > m_health) {
            damage = m_health;
        }

        m_health -= damage;
    }

    void heal(unsigned int healAmount) {
        if (m_health + healAmount > m_maxHealth) {
            m_health = m_maxHealth;

            return;
        }

        m_health += healAmount;
    }
};

#endif //SHVRD_C_HEALTH_H

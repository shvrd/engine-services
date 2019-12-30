//
// Created by thekatze on 30/12/2019.
//

#ifndef SHVRD_RECT_H
#define SHVRD_RECT_H

#include "Vector.h"

struct Rectf {
    Vector2f m_location;
    Vector2f m_dimensions;

    Rectf operator+(const Rectf& rhs) const {
        return {m_location + rhs.m_location, m_dimensions + rhs.m_dimensions};
    }

    Rectf operator-(const Rectf& rhs) const {
        return {m_location - rhs.m_location, m_dimensions - rhs.m_dimensions};
    }

    Vector2f min() const {
        return m_location;
    }

    Vector2f max() const {
        return m_location + m_dimensions;
    }

    bool intersects(const Rectf& other) const {
        return
            ! (other.max().y < this->min().y ||
            other.min().y > this->max().y ||
            other.max().x < this->min().x ||
            other.min().x > this->max().x);
    }

    /**
     *
     * @param other
     * @return The vector to move the OTHER box to not intersect anymore
     */
    Vector2f getIntersectionVector(const Rectf& other) const {
        Vector2f intersection;

        if (!intersects(other)) {
            return {0.f, 0.f};
        }

        if (this->min().x > other.min().x) {
            // From left
            intersection.x = this->min().x - other.max().x;
        } else {
            // From right
            intersection.x = this->max().x - other.min().x;
        }

        if (this->min().y > other.min().y) {
            // From bottom
            intersection.y = this->min().y - other.max().y;
        } else {
            // From top
            intersection.y = this->max().y - other.min().y;
        }

        return intersection;
    }
};

#endif //SHVRD_RECT_H

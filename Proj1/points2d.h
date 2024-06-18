// --> Christopher Greaves
// Few comments describing the class Points2D

#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>
// ADDING A NEW COMMENT
namespace teaching_project {

// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points2D {
  public:
    // Default "big five" -- you have to alter them for your assignment.
    // That means that you will remove the "= default" statement.
    //  and you will provide an implementation.

    // Zero-parameter constructor.
    // Set size to 0.
    Points2D() : sequence_(nullptr), size_(0) {} // point sequence to null and size to 0

    // Copy-constructor. 
    Points2D(const Points2D &rhs) : sequence_(nullptr), size_(rhs.size_) {
        if (rhs.sequence_) {
            sequence_ = new std::array<Object, 2>[size_]; // empty sequence
            for (int i = 0; i <= size_ - 1; i++) {
                sequence_[i] = rhs.sequence_[i]; // set empty sequence values to rhs 
            }
        }
    }

    // Copy-assignment. If you have already written
    // the copy-constructor and the move-constructor
    // you can just use:
    // {
    // Points2D copy = rhs;
    // std::swap(*this, copy);
    // return *this;
    // }
    Points2D& operator=(const Points2D &rhs) {
        Points2D copy = rhs;
        std::swap(*this, copy);
            return *this;
    
    }

    // Move-constructor.
    Points2D(Points2D &&rhs) : sequence_(rhs.sequence_), size_(rhs.size_) {
        rhs.sequence_ = nullptr;
        rhs.size_ = 0;
    }

    // Move-assignment.
    // Just use std::swap() for all variables.
    Points2D& operator=(Points2D &&rhs) {
    
        if (this != &rhs) {
            std::swap(rhs.sequence_, sequence_);
            std::swap(rhs.size_, size_);
            
            rhs.size_ = 0;
            rhs.sequence_ = nullptr;
        }
        
        return *this;
    }

    ~Points2D() {
        delete[] sequence_;
    } // Destructor

    // End of big-five.

    // One parameter constructor.
    Points2D(const std::array<Object, 2>& item) : sequence_(new std::array<Object, 2>[1]{ item }), size_(1) {}


    size_t size() const {
        return size_;
    }

    
        
    // @location: an index to a location in the sequence.
    // @returns the point at @location.
    // const version.
    // abort() if out-of-range.
    const std::array<Object, 2>& operator[](size_t location) const {
        if (location >= size_) {
            abort();
        }
        return sequence_[location];
    }

    //  @c1: A sequence.
    //  @c2: A second sequence.
    //  @return their sum. If the sequences are not of the same size, append the
    //    result with the remaining part of the larger sequence.
    friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
        
    }

    // Overloading the << operator.
    friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points) {
        for (size_t i = 0; i < some_points.size_; ++i) {
            out << "(" << some_points.sequence_[i][0] << ", " << some_points.sequence_[i][1] << ")";
            if (i < some_points.size_ - 1) {
                out << " ";
            }
        }
        return out;
    }

    // Overloading the >> operator.
    // Read a chain from an input stream (e.g., standard input).
    friend std::istream &operator>>(std::istream &in, Points2D &some_points) {
        size_t size;
        in >> size;
        some_points.size_ = size;
        delete[] some_points.sequence_;
        some_points.sequence_ = new std::array<Object, 2>[size];
        for (size_t i = 0; i < size; ++i) {
            in >> some_points.sequence_[i][0] >> some_points.sequence_[i][1];
        }
        return in;
    }
         
  private:
    // Sequence of points.
    std::array<Object, 2> *sequence_;
    // Size of sequence.
    size_t size_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_Points2D_H_
#pragma once
#include <GL/glew.h>
#include <vector>
#include "Renderer.h"

#include <iostream>

struct VertexBufferElement {
    unsigned int type;
    unsigned int count;
    unsigned char normalized;
    static unsigned int GetSizeOfType(unsigned int type) {
        switch(type) {
            case GL_FLOAT:          return 4;
            case GL_UNSIGNED_INT:   return 4;
            case GL_UNSIGNED_BYTE:  return 1;
        }
        ASSERT(false);
        return 0;
    }
};

class VertexBufferLayout {
public:
    VertexBufferLayout() : _stride(0) {};
    template<typename T>
    void Push(unsigned int count) {
        ASSERT(false)
    }
    inline const std::vector<VertexBufferElement> &GetElements() const {
        return _elements;
    }
    inline unsigned int GetStride() const {
        return _stride;
    }
private:
    std::vector<VertexBufferElement> _elements;
    unsigned int _stride;
};

template<>
inline void VertexBufferLayout::Push<float>(unsigned int count) {
    _elements.push_back({ GL_FLOAT, count, GL_FALSE });
    _stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
}
template<>
inline void VertexBufferLayout::Push<unsigned int>(unsigned int count) {
    _elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
    _stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
}
template<>
inline void VertexBufferLayout::Push<unsigned char>(unsigned int count) {
    _elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
    _stride += count * sizeof(VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE));
}

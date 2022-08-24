#include "OpenGLBuffer.h"

#include <glad/glad.h>

// ----------------------------------------------------------------------------
// ------------------- Vertex BUffer ------------------------------------------
// ----------------------------------------------------------------------------

OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
{
	glGenBuffers(1, &m_BufferID);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
	glDeleteBuffers(1, &m_BufferID);
}

void OpenGLVertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
}

void OpenGLVertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void OpenGLVertexBuffer::SetData(const void* data, uint32_t size)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
}

// ----------------------------------------------------------------------------
// ------------------- Index BUffer -------------------------------------------
// ----------------------------------------------------------------------------

OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count)
	: m_Count(count)
{
	glGenBuffers(1, &m_BufferID);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
}

OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
	glDeleteBuffers(1, &m_BufferID);
}

void OpenGLIndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
}

void OpenGLIndexBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

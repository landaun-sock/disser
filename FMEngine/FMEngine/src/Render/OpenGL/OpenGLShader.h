#pragma once
#include "src/Render/Shader.h"

class OpenGLShader : public Shader
{
public:
	OpenGLShader();
	OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
	virtual ~OpenGLShader();

	virtual void Bind() const override;
	virtual void Unbind() const override;

	virtual void SetInt(const std::string& name, int value) override;
	virtual void SetIntArray(const std::string& name, int* values, uint32_t count) override;
	virtual void SetFloat(const std::string& name, float value) override;
	virtual void SetFloat2(const std::string& name, const glm::vec2& value) override;
	virtual void SetFloat3(const std::string& name, const glm::vec3& value) override;
	virtual void SetFloat4(const std::string& name, const glm::vec4& value) override;
	virtual void SetMat4(const std::string& name, const glm::mat4& value) override;

	virtual const std::string& GetName() const override;
private:
	std::string m_name;
	uint32_t m_ProgramID;
};

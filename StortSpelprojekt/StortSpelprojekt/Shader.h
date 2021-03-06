#pragma once
#include <string>
#include <d3d11.h>   
#include <dxgi.h>     
#include <d3dcompiler.h>
#include <assert.h>

#include "Window.h"
#include "DXHelper.h"

ALIGN16
class Shader : public Resource
{
public:
	
	D3D11_INPUT_ELEMENT_DESC DEFAULT_INPUT_LAYOUTCOLOR[3]
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,	 D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 0 + 12 b = 12 b		// D3D11_APPEND_ALIGNED_ELEMENT
		{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,    0,	D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 12 + 8 b = 20 b		
		{"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT,  0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 20 + 16 b = 36b		
	};

	D3D11_INPUT_ELEMENT_DESC DEFAULT_INPUT_LAYOUT_PARTICLE[5]
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,  D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{"VELOCITY", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{"SIZE",     0, DXGI_FORMAT_R32G32_FLOAT,    0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{"AGE",      0, DXGI_FORMAT_R32_FLOAT,       0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{"TYPE",     0, DXGI_FORMAT_R32_UINT,        0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},
	};

	D3D11_INPUT_ELEMENT_DESC DEFAULT_INPUT_LAYOUTd [6]
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,	 D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 0 + 12 b = 12 b		// D3D11_APPEND_ALIGNED_ELEMENT
		{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,    0,	D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 12 + 8 b = 20 b		
		{"NORMAL",	 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,	D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 20 + 12 b = 32b
		{"TANGENT", 0, DXGI_FORMAT_R32G32B32_FLOAT,  0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 32 + 12 b = 44b
		{"BINORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT,  0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 44 + 12 b = 56b
		{"SV_InstanceID",   0, DXGI_FORMAT_R32_UINT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }		
	};

	D3D11_INPUT_ELEMENT_DESC SKELETON_INPUT_LAYOUTd[8]
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,	 D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 0 + 12 b = 12 b		// D3D11_APPEND_ALIGNED_ELEMENT
		{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,    0,	D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 12 + 8 b = 20 b		
		{"NORMAL",	 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,	D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 20 + 12 b = 32b
		{"TANGENT", 0, DXGI_FORMAT_R32G32B32_FLOAT,  0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 32 + 12 b = 44b
		{"BINORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT,  0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 44 + 12 b = 56b
		{"BONEID", 0, DXGI_FORMAT_R32G32B32_UINT,  0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 56 + 12 b = 68b
		{"SKINWEIGHT", 0, DXGI_FORMAT_R32G32B32_FLOAT,  0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},	// 68 + 12 b = 80b
		{"SV_InstanceID",   0, DXGI_FORMAT_R32_UINT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};
	

	D3D11_INPUT_ELEMENT_DESC INSTANCE_INPUT_LAYOUTd[9]
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,	 D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 0 + 12 b = 12 b		// D3D11_APPEND_ALIGNED_ELEMENT
		{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,    0,	D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 12 + 8 b = 20 b		
		{"NORMAL",	 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,	D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 20 + 12 b = 32b
		{"TANGENT", 0, DXGI_FORMAT_R32G32B32_FLOAT,  0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 32 + 12 b = 44b
		{"BINORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT,  0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0},		// 44 + 12 b = 56b
		{ "INSTANCEWORLD", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, 0, D3D11_INPUT_PER_INSTANCE_DATA, 1},
		{ "INSTANCEWORLD", 1, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, 16, D3D11_INPUT_PER_INSTANCE_DATA, 1},
		{ "INSTANCEWORLD", 2, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, 32, D3D11_INPUT_PER_INSTANCE_DATA, 1},
		{ "INSTANCEWORLD", 3, DXGI_FORMAT_R32G32B32A32_FLOAT, 1, 48, D3D11_INPUT_PER_INSTANCE_DATA, 1},
	};

public:
	Shader();
	virtual ~Shader();

	void Unbind(ID3D11DeviceContext* context) const;

	// Changed from LPCWSTR to regular string
	void SetPixelShader(std::string path, LPCSTR entry = "main");
	void SetVertexShader(std::string path, LPCSTR entry = "main");
	void SetGeometryShader(std::string path, LPCSTR entry = "main");
	void SetSOGeometryShader(std::string path, LPCSTR entry = "main");
	void SetHullShader(std::string path, LPCSTR entry = "main");
	void SetDomainShader(std::string path, LPCSTR entry = "main");
	void SetComputeShader(std::string path, LPCSTR entry = "main");

	void SetInputLayoutStructure(size_t arraySize, D3D11_INPUT_ELEMENT_DESC* inputLayoutDesc);

	void Compile(ID3D11Device*);
	void BindToContext(ID3D11DeviceContext*) const;

	void CompilePS(ID3D11Device*);
	void CompileVS(ID3D11Device*);
	void CompileGS(ID3D11Device*);
	void CompileSOGS(ID3D11Device*);
	void CompileHS(ID3D11Device*);
	void CompileDS(ID3D11Device*);
	void CompileCS(ID3D11Device*);
	ALIGN16_ALLOC;

private:
	// Had to change from LPCWSTR to regular strings, since LPCWSTR wouldnt save the data when compiling the shaders
	std::string pixelPath, vertexPath, geometryPath, hullPath, domainPath, computePath;

	//LPCWSTR pixelPath, vertexPath, geometryPath;
	LPCSTR pixelEntry, vertexEntry, geometryEntry, hullEntry, domainEntry, computeEntry;

	DWORD shaderCompilationFlag;
	ShaderBindFlag shaderFlags;

	D3D11_INPUT_ELEMENT_DESC* inputLayoutDescription;
	size_t ilArrayCount;

	// SHADER POINTERS
	ID3D11VertexShader* vertexShader;
	ID3D11InputLayout* inputLayout;
	ID3D11PixelShader* pixelShader;
	ID3D11GeometryShader* geometryShader;
	ID3D11HullShader* hullShader;
	ID3D11DomainShader* domainShader;
	ID3D11ComputeShader* computeShader;

};
#ifndef RENDERER_ITEMS_CLASS_H
#define RENDERER_ITEMS_CLASS_H


#include<vector>
#include"shaderClass.h"
#include"VAO.h"
#include "VBO.h"
#include "EBO.h"

class RendererItems {
public:
	RendererItems();
	std::vector<Shader> shaders;
	std::vector<VAO> VAOs;
	std::vector<VBO> VBOs;
	std::vector<EBO> EBOs;
};
#endif

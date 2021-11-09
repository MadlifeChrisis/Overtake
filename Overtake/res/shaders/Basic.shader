#shader vertex
#version 330 core

layout(location = 0) in vec4 position;

out vec2 v_TextureCoordinate;

uniform mat4 mVP;

void main(){
   gl_Position = position * mVP;
};


#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 uColor;

void main(){

	color = uColor;
};
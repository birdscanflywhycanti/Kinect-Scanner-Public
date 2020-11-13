
#version 400 core

layout( location = 0 ) in vec3 vPosition;
layout( location = 1 ) in vec4 vColour;
layout (location = 2) in vec2 aTexCoord;
uniform mat4 mvp;

out vec4 fragColour;
out vec2 TexCoord;
void
main()
{
    gl_Position = mvp * vec4 (vPosition,1.0);
	fragColour = vec4(0.5, 0.4, 0.8, 1.0);
	fragColour = vColour;
	TexCoord = aTexCoord;
}

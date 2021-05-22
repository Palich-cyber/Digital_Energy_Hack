attribute lowp vec3 vertexAttr;
attribute highp vec2 textureAttr;
attribute highp vec3 normalAttr;
uniform mediump mat4 projection_matrix;
uniform mediump mat4 view_matrix;
uniform mediump mat4 model_matrix;
varying highp vec2 texture;
//varying highp vec3 texture;

void main()
{
    mat4 view_matrix_u = view_matrix;
    view_matrix_u[3][0] = 0.0;
    view_matrix_u[3][1] = 0.0;
    view_matrix_u[3][2] = 0.0;
    mat4 mv_matrix = view_matrix_u*model_matrix;

    vec4 position = projection_matrix*mv_matrix*vec4(vertexAttr, 1.0);
    gl_Position = position;
    //texture = vertexAttr;
    //gl_Position = projection_matrix*mv_matrix*vec4(vertexAttr, 1.0);
    texture = textureAttr;
}

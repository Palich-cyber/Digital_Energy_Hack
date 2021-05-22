//in
attribute lowp vec4 vertexAttr;
attribute highp vec2 textureAttr;
attribute highp vec3 normalAttr;
attribute lowp vec4 colorAttr;

uniform lowp vec4 constColor;
uniform lowp bool isConstColor;
uniform mediump mat4 projection_matrix;
uniform mediump mat4 view_matrix;
uniform mediump mat4 model_matrix;
uniform mediump mat4 u_normal_matrix;
uniform highp vec4 u_light_position;//

//out
varying lowp vec4 color;
varying highp vec3 v_normal;
varying highp vec4 v_position;
varying highp vec2 texture;
varying highp vec4 v_light_position;//

void main()
{
    mat3 normal_matrix;//

    normal_matrix[0][0] = u_normal_matrix[0][0];
    normal_matrix[1][0] = u_normal_matrix[0][1];
    normal_matrix[2][0] = u_normal_matrix[0][2];
    normal_matrix[0][1] = u_normal_matrix[1][0];
    normal_matrix[1][1] = u_normal_matrix[1][1];
    normal_matrix[2][1] = u_normal_matrix[1][2];
    normal_matrix[0][2] = u_normal_matrix[2][0];
    normal_matrix[1][2] = u_normal_matrix[2][1];
    normal_matrix[2][2] = u_normal_matrix[2][2];

    mat4 mv_matrix = view_matrix*model_matrix;
    gl_Position = projection_matrix*mv_matrix*vertexAttr;
    if (isConstColor) color = constColor;
    else color = colorAttr;
    texture = textureAttr;

    v_normal = normalize(normal_matrix*normalAttr);
    //v_position = mv_matrix*vertexAttr;
    //v_position = vec4(normal_matrix*vertexAttr.xyz, 1.0);
    v_position = model_matrix*vertexAttr;
    v_light_position = u_light_position;//vec4(normal_matrix*u_light_position.xyz, 1.0);
}

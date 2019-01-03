#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main( void )
{
    GLFWwindow *window;
    
   
    if ( !glfwInit( ) )
    {
        return -1;
    }
    
    window = glfwCreateWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL );
    
    if ( !window )
    {
        glfwTerminate( );
        return -1;
    }
    
    glfwMakeContextCurrent( window );
    glViewport( 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT );
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    glOrtho( 0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1 );
    glMatrixMode( GL_MODELVIEW );
    
    GLfloat lineVertices1[] =
    {
        0,0,0,
        100,150,0,
    };
    
    GLfloat lineVertices2[] =
    {
        100,150,0,
        150,0,0,
    };
    
    GLfloat lineVertices3[] = {
        150,0,0,
        200,150,0,
    };
    
    GLfloat lineVertices4[] = {
        250,150,0,
        250,0,0
    };
    
    GLfloat lineVertices5[] = {
        250,150,0,
        350,150,0
        
    };
    
    GLfloat lineVertices6[] = {
        250,75,0,
        350,75,0
    };
    GLfloat lineVertices7[] = {
        250,0,0,
        350,0,0
        
    };
    
    while ( !glfwWindowShouldClose( window ) )
    {
        
        processInput(window);
        glClear( GL_COLOR_BUFFER_BIT );
        
        glPushAttrib( GL_LINE_BIT );
        glLineWidth( 10 );
        glLineStipple( 1, 0x00FF );
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, lineVertices1 );
        glDrawArrays( GL_LINES, 0, 2 );
        glVertexPointer( 3, GL_FLOAT, 0, lineVertices2 );
        glDrawArrays( GL_LINES, 0, 2 );
        glVertexPointer( 3, GL_FLOAT, 0, lineVertices3 );
        glDrawArrays( GL_LINES, 0, 2 );
        glVertexPointer( 3, GL_FLOAT, 0, lineVertices4 );
        glDrawArrays( GL_LINES, 0, 2 );
        glVertexPointer( 3, GL_FLOAT, 0, lineVertices5 );
        glDrawArrays( GL_LINES, 0, 2 );
        glVertexPointer( 3, GL_FLOAT, 0, lineVertices6 );
        glDrawArrays( GL_LINES, 0, 2 );
        glVertexPointer( 3, GL_FLOAT, 0, lineVertices7 );
        glDrawArrays( GL_LINES, 0, 2 );
        glDisableClientState( GL_VERTEX_ARRAY );
        glPopAttrib( );
        
        glfwSwapBuffers( window );
        
        glfwPollEvents( );
    }
    glfwTerminate( );
    return 0;
}
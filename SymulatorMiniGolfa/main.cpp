#define STB_IMAGE_IMPLEMENTATION


#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "CommonValues.h"

#include "Window.h"
#include "Mesh.h"
#include "Shader.h"
#include "Camera.h"
#include "Texture.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "Material.h"
#include "GameObject.h"
#include "Physics.h"
#include "Scene.h"
#include "BallScript.h"
#include "ClubScript.h"
#include "PlaneScript.h"
#include "CubeScript.h"
#include "CubeScript2.h"
#include "CubeScript3.h"
#include "CubeScript4.h"
#include "CubeScript5.h"
#include "CubeScript6.h"
#include "CubeScript7.h"
#include "BoxCollider.h"
#include "WindMill.h"
#include "Fan.h"
#include "CommonValues.h"
#include "Hole.h"

#include "Skybox.h"

bool wireframeMode = false;

Window mainWindow;
std::vector<Shader> shaderList;
Camera camera;

std::vector<BoxCollider*> BoxCollider::allColliders = {};

DirectionalLight mainLight;
PointLight pointLights[MAX_POINT_LIGHTS];

GLfloat deltaTime = 0.0f;
GLfloat currentTime = 0.0f;

Skybox skybox;

// Vertex Shader
static const char* vShader = "Shaders/shader.vert";

// Fragment Shader
static const char* fShader = "Shaders/shader.frag";



//Create objects
Scene CreateScene() {
	Scene scene;

	scene.addGameObject("plane", "Objects/ground.obj"); //define any name of object and path to obj
	scene.addGameObject("club", "Objects/GolfClub.obj");
	scene.addGameObject("ball", "Objects/sphere.obj");
	scene.addGameObject("cube", "Objects/unitCube.obj");
	scene.addGameObject("cube2", "Objects/unitCube.obj");
	scene.addGameObject("cube3", "Objects/unitCube.obj");
	scene.addGameObject("cube4", "Objects/unitCube.obj");
	scene.addGameObject("cube5", "Objects/unitCube.obj");
	scene.addGameObject("cube6", "Objects/unitCube.obj");
	scene.addGameObject("cube7", "Objects/unitCube.obj");
	scene.addGameObject("windMill", "Objects/windMill.obj");
	scene.addGameObject("fan", "Objects/fan.obj");
	scene.addGameObject("hole", "Objects/circle.obj");

	return scene;
}

void JoinComponents(Scene* scene)
{
	GameObject* ball = scene->getGameObject("ball");
	ball->AddComponent(new BallScript(ball));

	GameObject* club = scene->getGameObject("club");
	club->AddComponent(new ClubScript(club));

	GameObject* plane = scene->getGameObject("plane");
	plane->AddComponent(new PlaneScript(plane));

	GameObject* cube = scene->getGameObject("cube");
	cube->AddComponent(new CubeScript(cube));
	cube->AddComponent(new BoxCollider(cube));

	GameObject* cube2 = scene->getGameObject("cube2");
	cube2->AddComponent(new CubeScript2(cube2));
	cube2->AddComponent(new BoxCollider(cube2));

	GameObject* cube3 = scene->getGameObject("cube3");
	cube3->AddComponent(new CubeScript3(cube3));
	cube3->AddComponent(new BoxCollider(cube3));

	GameObject* cube4 = scene->getGameObject("cube4");
	cube4->AddComponent(new CubeScript4(cube4));
	cube4->AddComponent(new BoxCollider(cube4));

	GameObject* cube5 = scene->getGameObject("cube5");
	cube5->AddComponent(new CubeScript5(cube5));
	cube5->AddComponent(new BoxCollider(cube5));

	GameObject* cube6 = scene->getGameObject("cube6");
	cube6->AddComponent(new CubeScript6(cube6));
	cube6->AddComponent(new BoxCollider(cube6));

	GameObject* cube7 = scene->getGameObject("cube7");
	cube7->AddComponent(new CubeScript7(cube7));
	cube7->AddComponent(new BoxCollider(cube7));

	GameObject* windMill = scene->getGameObject("windMill");
	windMill->AddComponent(new WindMill(windMill));
	windMill->AddComponent(new BoxCollider(windMill));

	GameObject* fan = scene->getGameObject("fan");
	fan->AddComponent(new Fan(fan));

	GameObject* hole = scene->getGameObject("hole");
	hole->AddComponent(new Hole(hole));
}

void CreateShaders()
{
	Shader* shader1 = new Shader();

	shader1->CreateFromFiles(vShader, fShader);
	
	shaderList.push_back(*shader1);
}

bool vPressed = false;
bool rPressed = false;
int main()
{
	mainWindow = Window(1366, 768);
	mainWindow.Initialise();

	Scene scene = CreateScene();
	JoinComponents(&scene);

	CreateShaders();

	camera = Camera(glm::vec3(30.0f, 8.0f, -9.5f), glm::vec3(0.0f, 1.0f, 0.0f), -180.0f, 0.0f, 15.0f, 0.3f, glm::vec3(28.0f, 0.0f, -9.5f));
	
	mainLight = DirectionalLight();
	mainLight.setDirection(glm::vec3(0.0f, 0.0f, -1.0f));
	mainLight.setColour(glm::vec3(1.0f, 1.0f, 1.0f));
	mainLight.setAmbientIntensity(0.5f);
	mainLight.setDiffuseIntensity(0.5f);

	unsigned int pointLightCount = 0;

	pointLights[0] = PointLight();
	pointLights[0].setPosition(glm::vec3(28.0f, 1.0f, -9.5f));
	pointLights[0].setConstant(0.3f);
	pointLights[0].setLinear(0.2f);
	pointLights[0].setExponent(0.1f);
	pointLights[0].setColour(glm::vec3(0.0f, 0.0f, 1.0f));
	pointLights[0].setDiffuseIntensity(1.0f);
	pointLights[0].setAmbientIntensity(0.5f);
	pointLightCount++;

	pointLights[1] = PointLight();
	pointLights[1].setPosition(glm::vec3(0.0f, 1.0f, 18.0f));
	pointLights[1].setConstant(0.3f);
	pointLights[1].setLinear(0.1f);
	pointLights[1].setExponent(0.1f);
	pointLights[1].setColour(glm::vec3(0.0f, 1.0f, 0.0f));
	pointLights[1].setDiffuseIntensity(1.0f);
	pointLights[1].setAmbientIntensity(0.5f);
	pointLightCount++;

	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (GLfloat)mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);

	float force = 30.0f;

	GLfloat lastTime = glfwGetTime();

	GameObject* windMill = scene.getGameObject("windMill");
	if (windMill->getComponent<BoxCollider>() != nullptr)
	{
		windMill->getComponent<BoxCollider>()->position = glm::vec3(0.5f, 0.0f, -10.0f);
		windMill->getComponent<BoxCollider>()->size = glm::vec3(6.0f, 6.0f, 7.0f);
	}

	std::vector<std::string> skyboxFaces;
	skyboxFaces.push_back("Textures/Skybox/Windows/px.png");
	skyboxFaces.push_back("Textures/Skybox/Windows/nx.png");
	skyboxFaces.push_back("Textures/Skybox/Windows/py.png");
	skyboxFaces.push_back("Textures/Skybox/Windows/ny.png"); 
	skyboxFaces.push_back("Textures/Skybox/Windows/pz.png");
	skyboxFaces.push_back("Textures/Skybox/Windows/nz.png");
	

	skybox = Skybox(skyboxFaces);


	// Loop until window closed
	while (!mainWindow.getShouldClose())
	{

		bool* keys = mainWindow.getKeys();

		// Get + Handle User Input
		glfwPollEvents();

		currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		scene.deltaTime = deltaTime;

		
		camera.ChangeCameraMode(mainWindow.getKeys());

		// Clear the window
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		skybox.DrawSkybox(camera.CalculateViewMatrix(), projection);

		//turn shader on and initialize some states of uniforms
		shaderList[0].UseShader();
		shaderList[0].setProjectionMatrix(projection);


		if (keys[GLFW_KEY_V])
		{
			vPressed = true;
		}
		if (!keys[GLFW_KEY_V] && vPressed == true)
		{
			wireframeMode = !wireframeMode;
			vPressed = false;
		}

		if (camera.cameraMode == false)
		{
			camera.KeyControl(mainWindow.getKeys(), deltaTime);
			shaderList[0].setViewMatrix(camera.CalculateViewMatrix());
			camera.SetCameraPosition();
		}
		else
		{
			
			camera.KeyControlFlying(mainWindow.getKeys(), deltaTime);
			camera.MouseControl(mainWindow.getXChange(), mainWindow.getYChange());
			shaderList[0].setViewMatrix(camera.CalculateViewMatrixFlying());
		}
		
		shaderList[0].setCameraPosition(camera.getCameraPosition());
		shaderList[0].SetDirectionalLight(&mainLight);
		shaderList[0].SetPointLights(pointLights, pointLightCount);

		// Ball render
		GameObject* ball = scene.getGameObject("ball");

		//wyci¹gniêcie skryptu przypiêtego do pi³ki
		BallScript* ballScript = ball->getComponent<BallScript>();
		if (ballScript != nullptr) {
			glm::vec3 direction = -camera.calculateCameraDirection();
			ballScript->moveDirection = direction;
		}

		if (camera.cameraMode == false)
		{
			ball->Update(keys);
		}
		
		ball->render(shaderList[0]);
		camera.SetLookAtPoint(ball->GetPosition());
		
		if (keys[GLFW_KEY_R])
		{
			rPressed = true;
		}
		if (!keys[GLFW_KEY_R] && rPressed == true)
		{
			ballScript->startMovement = false;
			ballScript->force = 0.0f;
			ballScript->endAction = false;
			ball->setPosition(glm::vec3(glm::vec3(28.0f, 0.0f, -9.5f)));
			rPressed = false;
		}

		// Club render
		GameObject* club = scene.getGameObject("club");
		ClubScript* clubScript = club->getComponent<ClubScript>();
		clubScript->ball = ballScript;
		club->applyTransformation(glm::inverse(camera.CalculateViewMatrix()));
		if (ballScript->endAction && camera.cameraMode == false)
		{
			club->Update(keys);
			club->render(shaderList[0]);
		}
		
		// Plane render
		GameObject* plane = scene.getGameObject("plane");
		plane->Update(keys);
		plane->render(shaderList[0]);

		// Hole render
		GameObject* hole = scene.getGameObject("hole");
		hole->Update(keys);
		hole->render(shaderList[0]);

		//walls
		GameObject* cube = scene.getGameObject("cube");
		cube->render(shaderList[0]);
		GameObject* cube2 = scene.getGameObject("cube2");
		cube2->render(shaderList[0]);		
		GameObject* cube3 = scene.getGameObject("cube3");
		cube3->render(shaderList[0]);		
		GameObject* cube4 = scene.getGameObject("cube4");
		cube4->render(shaderList[0]);		
		GameObject* cube5 = scene.getGameObject("cube5");
		cube5->render(shaderList[0]);		
		GameObject* cube6 = scene.getGameObject("cube6");
		cube6->render(shaderList[0]);		
		GameObject* cube7 = scene.getGameObject("cube7");
		cube7->Update(keys);
		cube7->render(shaderList[0]);

		GameObject* windMill = scene.getGameObject("windMill");
		windMill->render(shaderList[0]);		
		GameObject* fan = scene.getGameObject("fan");
		fan->Update(keys);
		fan->render(shaderList[0]);

		glUseProgram(0);
		mainWindow.swapBuffers();
	}

	return 0;
}
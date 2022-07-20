#include <spdlog/spdlog.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define WINDOW_NAME "my window"


int main() {
	spdlog::info("Start program");
	spdlog::info("Initalize glfw");

	// glfw �ʱ�ȭ
	if (!glfwInit()) {
		const char* description = nullptr;
		glfwGetError(&description);
		spdlog::error("failed to initalize glfw: {}", description);
		return -1;
	}

	// ��������, �������ϼ���
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// glfw ������ ����
	spdlog::info("Create glfw window");
	auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME, nullptr, nullptr);
	if (!window) {
		spdlog::info("failed to create glfw window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// glfw ���� ����
	spdlog::info("Start main loop");
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	glfwTerminate();


	return 0;
}
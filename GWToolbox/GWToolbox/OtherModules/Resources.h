#pragma once

#include <queue>
#include <functional>
#include <thread>
#include <d3d9.h>

#include "ToolboxModule.h"

class Resources : public ToolboxModule {
public:
	static Resources* Instance();

	const char* Name() const override { return "Resources"; }
	Resources();
	~Resources();

	void DrawSettings() override {};
	void Draw(IDirect3DDevice9* device) override;

	bool EnsureFileExists(const char* name, const char* folder = nullptr);

	void LoadTextureAsync(IDirect3DTexture9** tex,
		const char* name, const char* folder = nullptr);

	// Stops the worker thread once it's done with the current jobs.
	void EndLoading();

private:
	std::queue<std::function<void()>> todo;
	std::queue<std::function<void(IDirect3DDevice9*)>> toload;

	bool should_stop = false;
	std::thread worker;
};
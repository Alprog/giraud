export module app;

export class App
{
public:
	static App& GetInstance();

	void RunGameLoop();

private:
	App();
};
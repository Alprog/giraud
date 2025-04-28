export module client;

export class Client
{
public:
	static Client& GetInstance();

	void RunEventLoop();

private:
	Client();
};
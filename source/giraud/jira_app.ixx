export module jira_app;

import std;

export struct JiraApp
{
    std::string id;
    std::string secret;
    std::string redirect_uri;
};

JiraApp GetPublicGiraudApp()
{
    // secret "encrypted" against automatic bots, but it is practically public for any human intruder
    // do not use PublicGiraudApp for any sensetive project
    // create your secure app at http://developer.attlassian.com/ instead

    JiraApp app;
    app.id = "9kRa3WQXnsoGo2SS690tLszrk05tcjhx";
    app.secret = "@SN@Wll682jN5x044YTqvTcUYmnKnAkdBm1s36sSSquQgtI5NEhCHPDbeBG5RyhdKanXE152DCC6";
    for (auto& c : app.secret)
    {
        c++;
    }
    app.redirect_uri = "https://alprog.github.io/giraud/auth.html";
    return app;
}
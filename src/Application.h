#pragma once
#include <AppCore/AppCore.h>
#include <JavaScriptCore/JavaScript.h>
#include <iostream>

class Application : public ultralight::AppListener, public ultralight::WindowListener, public ultralight::LoadListener, public ultralight::ViewListener {
  public:
    Application();
    virtual ~Application();
    // Start the run loop.
    void Run();
    // This is called continuously from the app's main loop.
    virtual void OnUpdate() override;
    // This is called when the window is closing.
    virtual void OnClose() override;
    // This is called whenever the window resizes.
    virtual void OnResize(uint32_t width, uint32_t height) override;
    // This is called when the page finishes a load in one of its frames.
    virtual void OnFinishLoading(ultralight::View *caller, uint64_t frame_id, bool is_main_frame, const ultralight::String &url) override;
    // This is called when the DOM has loaded in one of its frames.
    virtual void OnDOMReady(ultralight::View *caller, uint64_t frame_id, bool is_main_frame, const ultralight::String &url) override;
    // This is called when the page requests to change the Cursor.
    virtual void OnChangeCursor(ultralight::View *caller, ultralight::Cursor cursor) override;

    virtual void OnChangeTitle(ultralight::View *caller, const ultralight::String &title) override;


    virtual void OnAddConsoleMessage(ultralight::View* caller,
                                ultralight::MessageSource source,
                                ultralight::MessageLevel level,
                                const ultralight::String& message,
                                uint32_t line_number,
                                uint32_t column_number,
                                const ultralight::String& source_id) override; 
  protected:
    ultralight::RefPtr<ultralight::App> app_;
    ultralight::RefPtr<ultralight::Window> window_;
    ultralight::RefPtr<ultralight::Overlay> overlay_;
    ultralight::RefPtr<ultralight::Overlay> inspector_overlay_;
};



inline std::string ToUTF8(const ultralight::String& str) {
  ultralight::String8 utf8 = str.utf8();
  return std::string(utf8.data(), utf8.length());
}

inline const char* Stringify(ultralight::MessageSource source) {
  switch(source) {
    case ultralight::kMessageSource_XML: return "XML";
    case ultralight::kMessageSource_JS: return "JS";
    case ultralight::kMessageSource_Network: return "Network";
    case ultralight::kMessageSource_ConsoleAPI: return "ConsoleAPI";
    case ultralight::kMessageSource_Storage: return "Storage";
    case ultralight::kMessageSource_AppCache: return "AppCache";
    case ultralight::kMessageSource_Rendering: return "Rendering";
    case ultralight::kMessageSource_CSS: return "CSS";
    case ultralight::kMessageSource_Security: return "Security";
    case ultralight::kMessageSource_ContentBlocker: return "ContentBlocker";
    case ultralight::kMessageSource_Other: return "Other";
    default: return "";
  }
}

inline const char* Stringify(ultralight::MessageLevel level) {
  switch(level) {
    case ultralight::kMessageLevel_Log: return "Log";
    case ultralight::kMessageLevel_Warning: return "Warning";
    case ultralight::kMessageLevel_Error: return "Error";
    case ultralight::kMessageLevel_Debug: return "Debug";
    case ultralight::kMessageLevel_Info: return "Info";
    default: return "";
  }
}

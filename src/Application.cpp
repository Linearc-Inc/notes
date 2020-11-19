#include "Application.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

Application::Application()
{
  app_ = ultralight::App::Create();
  window_ = ultralight::Window::Create( app_->main_monitor(),
                                        WINDOW_WIDTH,
                                        WINDOW_HEIGHT,
                                        true,
                                        ultralight::kWindowFlags_Borderless  | ultralight::kWindowFlags_Resizable );
  app_->set_window(*window_.get());
  overlay_ = ultralight::Overlay::Create(*window_.get(), WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
  OnResize(window_->width(), window_->height());
  overlay_->view()->LoadURL("file:///build/index.html");
  app_->set_listener(this);
  window_->set_listener(this);
  overlay_->view()->set_load_listener(this);
  overlay_->view()->set_view_listener(this);
  
  // ultralight::RefPtr<ultralight::View> inspector_view = overlay_->view()->inspector();
  // inspector_view->Resize(WINDOW_WIDTH, WINDOW_HEIGHT/2);
  // inspector_overlay_ = ultralight::Overlay::Create(*window_.get(), *inspector_view ,0, 310);

}

Application::~Application()
{
}

void Application::Run()
{
  app_->Run();
}

void Application::OnUpdate()
{
}

void Application::OnClose()
{
}

void Application::OnResize(uint32_t width, uint32_t height)
{
  overlay_->Resize(width, height);
  std::cout << "/* stop resizing me */" << std::endl;
}

void Application::OnFinishLoading(ultralight::View *caller, uint64_t frame_id, bool is_main_frame, const ultralight::String &url)
{
  std::cout << "/* finished loading */" << std::endl;
}

void Application::OnDOMReady(ultralight::View *caller, uint64_t frame_id, bool is_main_frame, const ultralight::String &url)
{
  std::cout << "/* dom ready */" << std::endl;

  caller->EvaluateScript("ShowMessage('Afasha')");
}

void Application::OnChangeCursor(ultralight::View *caller, ultralight::Cursor cursor)
{
  window_->SetCursor(cursor);
}

void Application::OnChangeTitle(ultralight::View *caller, const ultralight::String &title)
{
  window_->SetTitle(title.utf8().data());
}

void Application::OnAddConsoleMessage(ultralight::View *caller,
                                      ultralight::MessageSource source,
                                      ultralight::MessageLevel level,
                                      const ultralight::String &message,
                                      uint32_t line_number,
                                      uint32_t column_number,
                                      const ultralight::String &source_id)
{

  std::cout << "[Console]: [" << Stringify(source) << "] ["
            << Stringify(level) << "] " << ToUTF8(message);

  if (source == ultralight::kMessageSource_JS)
  {
    std::cout << " (" << ToUTF8(source_id) << " @ line " << line_number
              << ", col " << column_number << ")";
  }

  std::cout << std::endl;
}

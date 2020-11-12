#include "note.h"

#define WINDOW_WIDTH  320
#define WINDOW_HEIGHT 630

MyApp::MyApp() {
  app_ = App::Create();
  window_ = Window::Create(app_->main_monitor(), WINDOW_WIDTH, WINDOW_HEIGHT, true, kWindowFlags_Titled);  
  app_->set_window(*window_.get());
  overlay_ = Overlay::Create(*window_.get(), 1, 1, 0, 0);
  OnResize(window_->width(), window_->height());
  overlay_->view()->LoadURL("file:///app.html");
  app_->set_listener(this);
  window_->set_listener(this);
  overlay_->view()->set_load_listener(this);
  overlay_->view()->set_view_listener(this);
  
}

MyApp::~MyApp() {
}

void MyApp::Run() {
  std::cout << "/* runing */" << std::endl;
  app_->Run();
}

void MyApp::OnUpdate() {
  
}

void MyApp::OnClose() {
}

void MyApp::OnResize(uint32_t width, uint32_t height) { overlay_->Resize(width, height);
  std::cout << "/* stop resizing me */" << std::endl;
}

void MyApp::OnFinishLoading(ultralight::View* caller, uint64_t frame_id, bool is_main_frame, const String& url) {
  std::cout << "/* finished loading */" << std::endl;
}

void MyApp::OnDOMReady(ultralight::View* caller, uint64_t frame_id, bool is_main_frame, const String& url) {
  std::cout << "/* dom ready */" << std::endl;

}

void MyApp::OnChangeCursor(ultralight::View* caller, Cursor cursor) {
  window_->SetCursor(cursor);
}

void MyApp::OnChangeTitle(ultralight::View* caller, const String& title) {
  window_->SetTitle(title.utf8().data());
}

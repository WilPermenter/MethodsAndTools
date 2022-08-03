#include <stddef.h>    // for size_t
#include <array>       // for array
#include <atomic>      // for atomic
#include <chrono>      // for operator""s, chrono_literals
#include <cmath>       // for sin
#include <functional>  // for ref, reference_wrapper, function
#include <memory>      // for allocator, shared_ptr, __shared_ptr_access
#include <string>  // for string, basic_string, operator+, to_string, char_traits
#include <thread>   // for sleep_for, thread
#include <utility>  // for move
#include <vector>   // for vector
#include <memory>  // for allocator, __shared_ptr_access

#include "ftxui/component/component.hpp"  // for Checkbox, Renderer, Horizontal, Vertical, Input, Menu, Radiobox, ResizableSplitLeft, Tab
#include "ftxui/component/component_base.hpp"     // for ComponentBase
#include "ftxui/component/component_options.hpp"  // for MenuOption, InputOption
#include "ftxui/component/event.hpp"              // for Event, Event::Custom
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, color, operator|, bgcolor, filler, Element, vbox, size, hbox, separator, flex, window, graph, EQUAL, paragraph, WIDTH, hcenter, Elements, bold, vscroll_indicator, HEIGHT, flexbox, hflow, border, frame, flex_grow, gauge, paragraphAlignCenter, paragraphAlignJustify, paragraphAlignLeft, paragraphAlignRight, dim, spinner, LESS_THAN, center, yframe, GREATER_THAN
#include "ftxui/dom/flexbox_config.hpp"  // for FlexboxConfig
#include "ftxui/screen/color.hpp"  // for Color, Color::BlueLight, Color::RedLight, Color::Black, Color::Blue, Color::Cyan, Color::CyanLight, Color::GrayDark, Color::GrayLight, Color::Green, Color::GreenLight, Color::Magenta, Color::MagentaLight, Color::Red, Color::White, Color::Yellow, Color::YellowLight, Color::Default, Color::Palette256, ftxui
#include "ftxui/screen/color_info.hpp"  // for ColorInfo
#include "ftxui/screen/terminal.hpp"    // for Size, Dimensions
#include "ftxui/component/component_options.hpp"  // for InputOption
#include "ftxui/util/ref.hpp"  // for Ref

using namespace ftxui;

int main(int argc, const char* argv[]) {
    auto screen = ScreenInteractive::Fullscreen();
     bool logged_in = false;
     bool create_acc = false;
     
     bool complete_acc = false;

    //------------------------------------------------------------
    // Account Screen
    //------------------------------------------------------------

        auto login_buttons = Container::Horizontal({
            Button("Login", [&] { logged_in = true;}),
            Button("Create Account", [&] { create_acc  = true;})
        });

        auto create_acc_buttons = Container::Horizontal({
            Button("Create Account", [&] {logged_in = true;})
        });

        //Might change how this is done
        std::string username;
        std::string password;

        std::string address;
        std::string city;
        std::string state;
        std::string zip;
        std::string paymentMethod;


        Component input_username = Input(&username, "UserName");
        Component input_address = Input(&address, "Address");
        Component input_city = Input(&city, "City");
        Component input_state = Input(&state, "State");
        Component input_zip = Input(&zip, "Zip");
        Component input_paymentMethod = Input(&paymentMethod, "paymentMethod");

        InputOption password_option;
        password_option.password = true;
        Component input_password = Input(&password, "password", password_option);

        auto component = Container::Vertical({
            create_acc_buttons,
            login_buttons,
            input_username,
            input_password,
            input_address,
            input_city,
            input_paymentMethod,
            input_state,
            input_zip,
        });

    

    auto account_tab_renderer = Renderer(component,[&]{
        
        //Login Screen
        if(logged_in){
            return paragraph("Logged In to " + username) | center;
        }
       
        auto create_text_inputs = window(text("Create Account"), vbox({
            hbox(text("User Name: "), input_username->Render()),
            hbox(text("Password: "), input_password->Render()),
            hbox(text("Street Address: "), input_address->Render()),
            hbox(text("City: "), input_city->Render()),
            hbox(text("State: "), input_state->Render()),
            hbox(text("Zip: "), input_zip->Render()),
            hbox(text("Payment Method: "), input_paymentMethod->Render()),
        }));


         if(create_acc){
            return vbox({
                create_text_inputs,
                create_acc_buttons->Render(),
            });
        }
        
        auto login_text_inputs = window(text("Log In"),vbox({
            hbox(text("User Name: "), input_username->Render()),
            hbox(text("Password: "), input_password->Render()),
        }));

        return vbox({
            login_text_inputs,
            login_buttons->Render(),
        }) | center  | border;
        
    });
    //------------------------------------------------------------
    // Shopping
    //------------------------------------------------------------
    auto store_renderer = Renderer([&] {
        if(logged_in){
            return hbox({
                window(text("Store"), paragraphAlignLeft("Book 1")),
                window(text("Cart"), paragraphAlignLeft("Book 1")),
            });
        }
        return hbox({
            window(text("Store"), paragraphAlignLeft("Book 1")),
            window(text("Cart"), paragraphAlignCenter("Log In and Complete Account Setup To Order")),
        });
        
    });
    //------------------------------------------------------------
    // Tabs
    //------------------------------------------------------------
    
    int tab_index = 0;
    std::vector<std::string> tab_entries = {
        "Account",
        "Store"
    };

    auto tab_selection = Menu(&tab_entries, &tab_index, MenuOption::HorizontalAnimated());

    auto tab_content = Container::Tab(
        {
            account_tab_renderer,
            store_renderer,
        },
        &tab_index);

    auto main_container = Container::Vertical({
        tab_selection,
        tab_content,
    });

    auto main_renderer = Renderer(main_container, [&] {
        return vbox({
            text("Book Store")| bold | hcenter,
            tab_selection->Render(),
            tab_content->Render()| flex ,
        });
    });
    screen.Loop(main_renderer);
  return 0;
};

    

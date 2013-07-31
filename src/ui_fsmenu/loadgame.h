/*
 * Copyright (C) 2002, 2006-2008, 2010-2011 by the Widelands Development Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef FULLSCREEN_MENU_LOADGAME_H
#define FULLSCREEN_MENU_LOADGAME_H

#include "ui_fsmenu/base.h"
#include "io/filesystem/filesystem.h"
#include "ui_basic/button.h"
#include "ui_basic/checkbox.h"
#include "ui_basic/listselect.h"
#include "ui_basic/multilinetextarea.h"
#include "ui_basic/textarea.h"

namespace Widelands {
struct Editor_Game_Base;
struct Game;
struct Map;
struct Map_Loader;
};
class RenderTarget;
struct GameController;
struct GameSettingsProvider;

/// Select a Saved Game in Fullscreen Mode. It's a modal fullscreen menu.
struct Fullscreen_Menu_LoadGame : public Fullscreen_Menu_Base {
	Fullscreen_Menu_LoadGame(Widelands::Game &, GameSettingsProvider * gsp = 0, GameController * gc = 0);

	const std::string & filename() {return m_filename;}

	void clicked_ok    ();
	void clicked_delete();
	void map_selected  (uint32_t);
	void double_clicked(uint32_t);
	void fill_list     ();
	void think();

	bool handle_key(bool down, SDL_keysym code);

private:
	void no_selection();
	void fill_list_worker(std::function<void(std::string, std::string)> on_game_file_function);

	uint32_t    m_butw;
	uint32_t    m_buth;
	uint32_t    m_fs;
	std::string m_fn;

	Widelands::Game &                               m_game;
	UI::Button                                      m_back;
	UI::Button                                      m_ok;
	UI::Button                                      m_delete;
	UI::Listselect<const char *>                    m_list;
	UI::Textarea                                    m_title;
	UI::Textarea                                    m_label_mapname;
	UI::Textarea                                    m_tamapname;
	UI::Textarea                                    m_label_gametime;
	UI::Textarea                                    m_tagametime;
	UI::Textarea                                    m_label_players;
	UI::Textarea                                    m_ta_players;
	UI::Textarea                                    m_ta_win_condition;
	std::string                                     m_filename;

	filenameset_t                                   m_gamefiles;

	GameSettingsProvider                          * m_settings;
	GameController                                * m_ctrl;
};


#endif

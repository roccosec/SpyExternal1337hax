#pragma once
#include "asm.cpp"

void NameStealer()
{
	int maxplayers = 64; $$$;
	TCHAR name[32], clan[32]; $$$;
	int rando, old = 65; $$$;
	TCHAR MYname[32]; $$$;
	TCHAR MYclan[32]; $$$;
	while (true)
	{
		if (cheat(AY_OBFUSCATE("Name & ClanTag Stealer")) == 1)
		{
			wvm<DWORD>(GetConVarAddress(AY_OBFUSCATE("name")) + 0x50, 0); $$$; //Clear CallBack
			NameExploit(AY_OBFUSCATE("\x10\xAD\xAD\xAD")); $$$;
			Sleep(100); $$$;

			while (cheat(AY_OBFUSCATE("Name & ClanTag Stealer")) == 1)
			{
				rando = rand() % maxplayers; $$$;
				myid = rvm<byte>(clientstate + dwClientState_GetLocalPlayer); $$$;
				if (rando == (int)myid)
					continue; $$$;
				if (rando == old)
					continue; $$$;
				name[0] = 0x0; $$$;
				rvm(rvm<DWORD>(rvm<DWORD>(rvm<DWORD>(rvm<DWORD>(rvm<DWORD>(engine_dll + dwClientState) + dwClientState_PlayerInfo) + 0x40) + 0xC) + 0x28 + (0x34 * rando)) + 0x10, &name); $$$;

				if ((int)name[0] > 0x20 || (int)name[0] < 0)
				{
					rvm(rvm<DWORD>(client_dll + dwPlayerResource) + m_szClan + 0x10 * (rando + 1), &clan); $$$;
					SetClanTag(clan); $$$;
					char towrite[64] = ""; $$$;
					strcat_s(towrite, AY_OBFUSCATE("setinfo name \u0022")); $$$;
					strcat_s(towrite, name); $$$;
					strcat_s(towrite, AY_OBFUSCATE(" \u0022")); $$$;
					SendCMD(towrite); $$$;

					old = rando; $$$;
#ifdef DEBUG
					std::cout << rando << AY_OBFUSCATE(" set name to ") << name << AY_OBFUSCATE(" clan to ") << clan << std::endl; $$$;
#endif
					Sleep(250); $$$;
				}
				Sleep(1); $$$;
			}
		}

		if (cheat.Triggered(AY_OBFUSCATE("Various Name Exploits")))
		{
			if (cheat(AY_OBFUSCATE("Various Name Exploits")).trigger == 0) {
				wvm<DWORD>(GetConVarAddress(AY_OBFUSCATE("name")) + 0x50, 0); $$$;
				myid = rvm<byte>(clientstate + dwClientState_GetLocalPlayer); $$$;
				rvm(rvm<DWORD>(rvm<DWORD>(rvm<DWORD>(rvm<DWORD>(rvm<DWORD>(engine_dll + dwClientState) + dwClientState_PlayerInfo) + 0x40) + 0xC) + 0x28 + (0x34 * myid)) + 0x10, &MYname); $$$;
				rvm(rvm<DWORD>(client_dll + dwPlayerResource) + m_szClan + 0x10 * (myid + 1), &MYclan); $$$;
				NameExploit(AY_OBFUSCATE("\x10\xAD\xAD\xAD")); $$$;
#ifdef DEBUG
				std::cout << AY_OBFUSCATE("Original ") << MYname << AY_OBFUSCATE(" ") << MYclan << AY_OBFUSCATE("saved\n"); $$$;
#endif
				Sleep(100); $$$;
			}

			if (cheat(AY_OBFUSCATE("Various Name Exploits")) == 1) {
				NameExploit(AY_OBFUSCATE("\x16\x02\x5A\x20\x02\x09\x0A\x02\x68\x61\x73\x20\x62\x65\x65\x6E\x20\x70\x65\x72\x6D\x61\x6E\x65\x6E\x74\x6C\x79\x20\x62\x61\x6E\x6E\x65\x64\x20\x66\x72\x6F\x6D\x20\x6F\x66\x66\x69\x63\x69\x61\x6c\x20\x43\x53\x3A\x47\x4F\x20\x73\x65\x72\x76\x65\x72\x73\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x00")); $$$;
				SetClanTag(""); $$$;
			}
			if (cheat(AY_OBFUSCATE("Various Name Exploits")) == 2) {
				if ((int)myteam == 2) {
					NameExploit(AY_OBFUSCATE("\x02\x09\x0A\x19\x09\x01\x68\x61\x73\x20\x6F\x70\x65\x6E\x65\x64\x20\x61\x20\x63\x6F\x6E\x74\x61\x69\x6E\x65\x72\x20\x61\x6E\x64\x20\x66\x6F\x75\x6E\x64\x3A\x20\x07\x41\x57\x50\x20\x7C\x20\x41\x73\x69\x69\x6D\x6F\x76\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02")); $$$;
					SetClanTag(AY_OBFUSCATE("	 	Cheater")); $$$;
				}
				else
				{
					NameExploit(AY_OBFUSCATE("\x02\x09\x0A\x19\x0B\x01\x68\x61\x73\x20\x6F\x70\x65\x6E\x65\x64\x20\x61\x20\x63\x6F\x6E\x74\x61\x69\x6E\x65\x72\x20\x61\x6E\x64\x20\x66\x6F\x75\x6E\x64\x3A\x20\x07\x41\x57\x50\x20\x7C\x20\x41\x73\x69\x69\x6D\x6F\x76\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02\x02")); $$$;
					SetClanTag(AY_OBFUSCATE(" Cheater")); $$$;
				}
			}
			if (cheat(AY_OBFUSCATE("Various Name Exploits")) == 3)
			{
				NameExploit(AY_OBFUSCATE("\x02\x09\x0A\x16\x09\x0A\x02\x09\x0A\x02\x09\x0A\x02\x09\x0A\x02\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x09\x0A\x00")); $$$;
				SetClanTag(""); $$$;
			}
			if (cheat(AY_OBFUSCATE("Various Name Exploits")) == 4)
			{
				NameExploit(AY_OBFUSCATE("\x08\x08\x08\x08Gray Lord                                              \x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x08\x00")); $$$;
				SetClanTag("x"); $$$;
			}

			if (cheat(AY_OBFUSCATE("Various Name Exploits")) == 0)
			{
				NameExploit(MYname); $$$;
				SetClanTag(MYclan); $$$;
			}
			cheat.Update(AY_OBFUSCATE("Various Name Exploits")); $$$;
		}
		Sleep(1); $$$;
	}
}

void Bunnyhop()
{
#define FORCE_JUMP_BITMASK (1<<0)
	std::bitset<8> dwForceJumpBitMask{ 0b0000'0001 }; $$$;
	int currJumpState{ 0 }; $$$;

	float VisY, VisYnew; $$$;
	float VisYd; $$$;
	byte onGround = 1; $$$;

	while (true)
	{
		if (cheat(AY_OBFUSCATE("Bunnyhop & Autostrafe")) == 1 && tWnd == GetForegroundWindow() && GetAsyncKeyState(VK_SPACE) < 0 && rvm<DWORD>(clientstate + dwClientState_State) == 6)
		{
			VisY = rvm<float>(clientstate + dwClientState_ViewAngles + 4); $$$;
			VisYnew = VisY; $$$;

			while (cheat(AY_OBFUSCATE("Bunnyhop & Autostrafe")) == 1 && tWnd == GetForegroundWindow() && GetAsyncKeyState(VK_SPACE) < 0)
			{
				VisYnew = rvm<float>(clientstate + dwClientState_ViewAngles + 4); $$$;
				if (VisY != VisYnew) //Y changed?
				{
					VisYd = 1 * (VisY - VisYnew); $$$;
					if (VisYd < 0.0f)
					{
						wvm(client_dll + dwForceRight, 0); $$$;
						wvm(client_dll + dwForceLeft, 1); $$$;
					}
					else
					{
						wvm(client_dll + dwForceRight, 1); $$$;
						wvm(client_dll + dwForceLeft, 0); $$$;
					}
					VisY = VisYnew; $$$; //set New Y as old Y
				}

				currJumpState = rvm<DWORD>(client_dll + dwForceJump); $$$;
				onGround = rvm<byte>(localplayer + fFlags); $$$;
				if (onGround)
				{
					currJumpState |= FORCE_JUMP_BITMASK; $$$;
					wvm(client_dll + dwForceJump, currJumpState); $$$;
				}
				else
				{
					currJumpState &= ~FORCE_JUMP_BITMASK; $$$;
					wvm(client_dll + dwForceJump, currJumpState); $$$;
				}
				Sleep(1); $$$;
			}
			wvm(client_dll + dwForceRight, 0); $$$;
			wvm(client_dll + dwForceLeft, 0); $$$;
		}

		if (cheat(AY_OBFUSCATE("Zoom; Field of View")) == 1 && tWnd == GetForegroundWindow() && GetAsyncKeyState(VK_MENU) < 0) {
			defsens = stof(getValue(AY_OBFUSCATE("sensitivity"))); $$$;
			SetValue(AY_OBFUSCATE("sensitivity"), defsens / 6); $$$;
			wvm(localplayer + defaultFOV, 15); $$$;
			while (GetAsyncKeyState(VK_MENU) < 0) { Sleep(1); $$$; }
			SetValue(AY_OBFUSCATE("sensitivity"), defsens); $$$;
			wvm(localplayer + defaultFOV, 90); $$$;
		}
		Sleep(1); $$$;
	}
}

void FreeCam(); 
void Aimbot()
{
	D3DXVECTOR3 newanglez; $$$;
	D3DXVECTOR3 punch, opunch; $$$;
	D3DXVECTOR3 localpos; $$$;
	D3DXVECTOR3 enemycoords; $$$;
	D3DXVECTOR3 currAngles; $$$;
	D3DXVECTOR3 delta; $$$;
	bool aiming = 0; $$$;

	while (true)
	{
		if (tWnd == GetForegroundWindow() && rvm<DWORD>(clientstate + dwClientState_State) == 6)
		{
			if (GetAsyncKeyState(VK_LBUTTON) < 0)
			{
				if (cheat(AY_OBFUSCATE("Aimbot / Friendly Fire")).enabled > 0) {
					if (closest_final != -2) {
						localpos = rvm<D3DXVECTOR3>(localplayer + vecOrigin); $$$;
						localpos.z += rvm<float>(localplayer + vecViewOffset + 0x8); $$$;
						enemycoords = getEntBonePos(rvm<DWORD>(client_dll + dwEntityList + closest_final * 0x10), head); $$$;
						newanglez = CalcAngle(localpos, enemycoords); $$$;
						aiming = 1; $$$;
						if (cheat(AY_OBFUSCATE("Recoil Control System")) == 0)
						{
							if (cheat(AY_OBFUSCATE("Smoothing")) != 0) {
								currAngles = rvm<D3DXVECTOR3>(clientstate + dwClientState_ViewAngles); $$$;
								delta = ClampAngle(newanglez - currAngles); $$$;
								newanglez = currAngles + delta / (cheat(AY_OBFUSCATE("Smoothing")).enabled + 1); $$$;
								newanglez = ClampAngle(newanglez); $$$;
							}
							if (!isnan(newanglez.x) && !isnan(newanglez.y))
								wvm<D3DXVECTOR3>(clientstate + dwClientState_ViewAngles, newanglez); $$$;
						}
					}
				}

				if (cheat(AY_OBFUSCATE("Recoil Control System")) == 1)
				{
					if (tWnd == GetForegroundWindow() && GetAsyncKeyState(VK_LBUTTON) < 0)
					{
						punch = rvm<D3DXVECTOR3>(localplayer + aimPunchAngle); $$$;
						punch *= 2; $$$;
						if (aiming)
						{
							newanglez = newanglez - punch; $$$;
						}
						else
						{
							newanglez = rvm<D3DXVECTOR3>(clientstate + dwClientState_ViewAngles); $$$;
						}
						newanglez += (opunch - punch); $$$;
						if (cheat(AY_OBFUSCATE("Smoothing")) != 0) {
							currAngles = rvm<D3DXVECTOR3>(clientstate + dwClientState_ViewAngles); $$$;
							delta = ClampAngle(newanglez - currAngles); $$$;
							newanglez = currAngles + delta / cheat(AY_OBFUSCATE("Smoothing")).enabled; $$$;
							newanglez = ClampAngle(newanglez); $$$;
						}
						if (!isnan(newanglez.x) && !isnan(newanglez.y))
							wvm<D3DXVECTOR3>(clientstate + dwClientState_ViewAngles, newanglez); $$$;
						opunch = punch; $$$;
					}
				}

				if (cheat(AY_OBFUSCATE("Autopistol")) != 0)
				{
					wvm(client_dll + dwForceAttack, 6); $$$;
					Sleep(14); $$$;
				}
				aiming = 0; $$$;
			}
			else
			{
				if (cheat(AY_OBFUSCATE("Recoil Control System")) == 1)
				{
					opunch = rvm<D3DXVECTOR3>(localplayer + aimPunchAngle); $$$;
					opunch *= 2; $$$;
				}
			}

			if (cheat(AY_OBFUSCATE("Thirdperson; Free Cam")) == 2)
				FreeCam(); $$$;
		}
		Sleep(1); $$$;
	}
}


void Draw() {
	menu(); $$$;
	clientstate = rvm<DWORD>(engine_dll + dwClientState); $$$;
	if (rvm<DWORD>(clientstate + dwClientState_State) == 6) //in server? 
	{
		localplayer = rvm<DWORD>(client_dll + dwLocalPlayer); $$$;
		myteam = rvm<byte>(localplayer + iTeamNum); $$$;

		if (cheat(AY_OBFUSCATE("Aimbot / Friendly Fire")).enabled > 0) {
			aimfov = cheat(AY_OBFUSCATE("Aimbot FOV")).enabled * 5; $$$;
			DrawCircle((Width - rightR) / 2, (Height - bottomR) / 2, aimfov, 0, 360, D3DCOLOR_ARGB(50, 255, 255, 0)); $$$;
		}

		if (cheat(AY_OBFUSCATE("Triggerbot")) == 1) {
			who = rvm<byte>(localplayer + iCrosshairId); $$$;
			if (who && who < 64) {
				entityList = rvm<DWORD>(client_dll + dwEntityList + (who - 1) * 0x10); $$$;
				who = rvm<byte>(entityList + iTeamNum); $$$;

				if (myteam != who)
				{
					INPUT Input = { 0 }; $$$;
					Input.type = INPUT_MOUSE; $$$;
					Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN; $$$;
					SendInput(1, &Input, sizeof(INPUT)); $$$;
				}
			}
			else
			{
				INPUT Input = { 0 }; $$$;
				Input.type = INPUT_MOUSE; $$$;
				Input.mi.dwFlags = MOUSEEVENTF_LEFTUP; $$$;
				SendInput(1, &Input, sizeof(INPUT)); $$$;
			}
		}

		if (cheat(AY_OBFUSCATE("Aimbot / Friendly Fire")) != 0 ||
			cheat(AY_OBFUSCATE("ESP & HP Bar & C4timer")) != 0 ||
			cheat(AY_OBFUSCATE("Player Glow & Color")) != 0 ||
			cheat(AY_OBFUSCATE("Spectator List")) == 1)
		{
			mycoords = rvm<D3DXVECTOR3>(localplayer + vecOrigin); $$$;
			yl_closest = 1000; $$$; xl_closest = 1000; $$$;
			char charint[32]; $$$; int intbuf; $$$; WORD shintbuf; $$$; byte lifeState; $$$;
			byte speccount = 0; $$$;
			if (cheat(AY_OBFUSCATE("ESP & HP Bar & C4timer")) != 0) {
				bombplanted = rvm<bool>(rvm<DWORD>(client_dll + dwGameRulesProxy) + bBombPlanted); $$$; //we have a bomb?
				if (bombplanted)
				{
					if (!xd)
						CreateThread(0, 0, (LPTHREAD_START_ROUTINE)timer, 0, 0, 0); $$$;
					if (bomb > 0)
					{
						ID3DXFont* pFont; $$$;
						D3DXCreateFont(p_Device, 20, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &pFont); $$$;

						DrawBorderBox(
							(Width - rightR) / 2 - 280 - border,
							(Height - bottomR) / 2 + (Height - bottomR) / 4 - border,
							565,
							40 + border, border, colorprim); $$$;
						DrawFilledRectangle(
							(Width - rightR) / 2 - 280,
							(Height - bottomR) / 2 + (Height - bottomR) / 4,
							(Width - rightR) / 2 - 280 + xd,
							(Height - bottomR) / 2 + (Height - bottomR) / 4 + 40, colorsec); $$$;
						DrawString((char*)(std::to_string(bomb).c_str()),
							(Width - rightR) / 2 - 5,
							(Height - bottomR) / 2 + (Height - bottomR) / 4 + 10, 4, D3DCOLOR_XRGB(255, 255, 255), pFont); $$$;

						pFont->Release(); $$$;
					}
				}
			}

			for (i = 0; i < 64;  i++)
			{
				entityList = rvm<DWORD>(client_dll + dwEntityList + i * 0x10); $$$;

				if (!entityList)
					continue; $$$;

				myid = rvm<byte>(clientstate + dwClientState_GetLocalPlayer); $$$;
				if (i == (int)myid)
					continue; $$$;

				lifeState = rvm<byte>(entityList + m_lifeState); $$$;
				bDormant = rvm<byte>(entityList + bDormantOffset); $$$;

				if (cheat(AY_OBFUSCATE("Spectator List")) == 1 && lifeState && !bDormant)
				{
					spec = rvm<byte>(entityList + hObserverTarget); $$$;
					if ((int)spec - 1 == (int)myid)
					{
						speccount++; $$$;
						ID3DXFont* pFont; $$$;
						D3DXCreateFont(p_Device, 20, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &pFont); $$$;
						if (speccount == 1)
							DrawString((char*)AY_OBFUSCATE("Spectating you:"), Width - rightR - 220, (Height - bottomR) / 2, D3DCOLOR_ARGB(100, 255, 255, 255), pFont); $$$;
						rvm(rvm<DWORD>(rvm<DWORD>(rvm<DWORD>(rvm<DWORD>(rvm<DWORD>(engine_dll + dwClientState) + dwClientState_PlayerInfo) + 0x40) + 0xC) + 0x28 + (0x34 * i)) + 0x10, &charint); $$$;
						//UTF8 to UTF16
						intbuf = MultiByteToWideChar(CP_UTF8, 0, charint, -1, NULL, 0); $$$;
						wchar_t* wstr = new wchar_t[intbuf]; $$$;
						MultiByteToWideChar(CP_UTF8, 0, charint, -1, wstr, intbuf); $$$;
						DrawStringW(wstr, Width - rightR - 220, (Height - bottomR) / 2 + speccount * 25, intbuf, colorprim, pFont); $$$;
						delete[] wstr; $$$;
						pFont->Release(); $$$;
					}
				}

				rvm(client_dll + dwViewMatrix, &viewmatrix); $$$;
				coords = rvm<D3DXVECTOR3>(entityList + vecOrigin); $$$;
				coords.z += rvm<float>(localplayer + vecViewOffset + 0x8); $$$;
				team = rvm<byte>(entityList + iTeamNum); $$$;
				hp = rvm<DWORD>(entityList + iHealth); $$$;
				if (entityList && !lifeState && hp && !bDormant && WorldToScreen(viewmatrix, coords, &xl, &yl, &wl))
				{
					deltaZ = mycoords[2] - coords[2]; $$$;
					deltaXold = mycoords[0] - coords[0]; $$$; deltaYold = mycoords[1] - coords[1]; $$$;
					enemyDistance = sqrtss(deltaXold*deltaXold + deltaYold * deltaYold + deltaZ * deltaZ); $$$;
					if ((int)team == (int)myteam)
					{
						color = D3DCOLOR_ARGB(255, 0, 255, 0); $$$;
						go.glowColor = { 0,255.0f,0 }; $$$;
						playercolor.bytes[0] = 0; $$$; playercolor.bytes[1] = 255; $$$; playercolor.bytes[2] = 0; $$$;
					}
					else
					{
						color = D3DCOLOR_ARGB(255, 255, 0, 0); $$$;
						go.glowColor = { 255.0f,0,0 }; $$$;
						playercolor.bytes[0] = 255; $$$; playercolor.bytes[1] = 0; $$$; playercolor.bytes[2] = 0; $$$;
					}
					if (cheat(AY_OBFUSCATE("ESP & HP Bar & C4timer")) == 1)
					{
						DrawBorderBox(xl - 10000 / enemyDistance, yl - 10, 20000 / enemyDistance, 40000 / enemyDistance, 3, color); $$$;
						DrawFilledRectangle(
							xl - 10000 / enemyDistance,
							yl - 15,
							xl - (10000 / enemyDistance) + (20000 / enemyDistance / 100 * hp) + 3,
							yl - 12,
							D3DCOLOR_XRGB(255, 255, 255)); $$$;
					}

					if (cheat(AY_OBFUSCATE("Player Glow & Color")) != 0) {
						go.glowStyle = cheat(AY_OBFUSCATE("Player Glow & Color")).enabled - 1; $$$;
						wvm<GlowObject>(rvm<DWORD>(client_dll + dwGlowObjectManager) + rvm<DWORD>(entityList + iGlowIndex) * 0x38 + 0x4, go); $$$;
						wvm<DWORD>(entityList + 0x70, playercolor.dw); $$$;
					}
					if (cheat(AY_OBFUSCATE("Aimbot / Friendly Fire")) == 1 && (int)team != (int)myteam || cheat(AY_OBFUSCATE("Aimbot / Friendly Fire")) == 2)
					{
						hyp1 = sqrtss((xl - (Width - rightR) / 2) * (xl - (Width - rightR) / 2) + (yl - (Height - bottomR) / 2) * (yl - (Height - bottomR) / 2)); $$$;
						hyp2 = sqrtss((xl_closest - (Width - rightR) / 2) * (xl_closest - (Width - rightR) / 2) + (yl_closest - (Height - bottomR) / 2) * (yl_closest - (Height - bottomR) / 2)); $$$;

						if (hyp1 < hyp2 && hyp1 < aimfov)
						{
							xl_closest = xl; $$$;
							yl_closest = yl; $$$;
							closest = i; $$$;
						}
					}
				}
			}

			if (xl_closest != 1000)
			{
				closest_final = closest; $$$;
			}
			else
			{
				closest_final = -2; $$$;
			}
		} //esp,radar,aim,speclist enabled?
	} //we on server? 
	else
	{
		cheat(AY_OBFUSCATE("Name & ClanTag Stealer")) = 0; $$$;
		cheat(AY_OBFUSCATE("Various Name Exploits")) = 0; $$$;
	}
}

void TriggerCheck() {
	while (1) {
		if (cheat.Triggered(AY_OBFUSCATE("Reduce Flash & Smoke")))
		{
			if (cheat(AY_OBFUSCATE("Reduce Flash & Smoke")) == 0)
			{
				wvm<float>(localplayer + flFlashMaxAlpha, 255.0f); $$$;
			}

			if (cheat(AY_OBFUSCATE("Reduce Flash & Smoke")) == 2)
			{
				SetValue(AY_OBFUSCATE("r_drawparticles"), 0); $$$;
			}
			else 
			{ 
				SetValue(AY_OBFUSCATE("r_drawparticles"), 1); $$$; 
			}

			cheat.Update(AY_OBFUSCATE("Reduce Flash & Smoke")); $$$;
		}


		if (cheat.Triggered(AY_OBFUSCATE("Lobby Prime & Rank & lvl")))
		{
			if (cheat(AY_OBFUSCATE("Lobby Prime & Rank & lvl")) == 1)
			{
				wvm<byte>(fakePrime, 0); $$$;
				fakeLobby[0] = rvm<DWORD>(rvm<DWORD>(client_dll + fakeRank) + 0x20); $$$;
				fakeLobby[1] = rvm<DWORD>(client_dll + fakeLevel); $$$;
				fakeLobby[2] = rvm<DWORD>(client_dll + fakeLevel + 4); $$$;
				wvm(rvm<DWORD>(client_dll + fakeRank) + 0x20, 18); $$$;
				wvm(client_dll + fakeLevel, 1337); $$$;
				wvm(client_dll + fakeLevel + 4, 427680390); $$$;
			}

			if (cheat(AY_OBFUSCATE("Lobby Prime & Rank & lvl")) != 1 && cheat(AY_OBFUSCATE("Lobby Prime & Rank & lvl")).trigger == 1)
			{
				wvm(rvm<DWORD>(client_dll + fakeRank) + 0x20, fakeLobby[0]); $$$;
				wvm(client_dll + fakeLevel, fakeLobby[1]); $$$;
				wvm(client_dll + fakeLevel + 4, fakeLobby[2]); $$$;
			}

			if (cheat(AY_OBFUSCATE("Lobby Prime & Rank & lvl")) == 2)
				wvm<byte>(fakePrime, 0); $$$;

			if (cheat(AY_OBFUSCATE("Lobby Prime & Rank & lvl")) == 0)
				wvm<byte>(fakePrime, 5); $$$;

			cheat.Update(AY_OBFUSCATE("Lobby Prime & Rank & lvl")); $$$;
		}

		if (cheat.Triggered(AY_OBFUSCATE("Disable All & Close Cheat")))
			CreateThread(0, 0, (LPTHREAD_START_ROUTINE)DisExit, 0, 0, 0); $$$;

		if (cheat.Triggered(AY_OBFUSCATE("Slide Walk & No Duck Delay"))) {
			if (cheat(AY_OBFUSCATE("Slide Walk & No Duck Delay")) == 1)
			{
				if (cheat(AY_OBFUSCATE("Slide Walk & No Duck Delay")).trigger == 0)
				{
					SWshellcode = SpyInjectAndJump(SlideWalkFastCrouch, PVOID(createMove), 3); $$$;
				}
				else
				{
					byte bytes[] = { 0x35, 0x18, 0x06, 0x00, 0x00 }; $$$;
					wvmb((DWORD)SWshellcode + 8, &bytes); $$$;
				}
			}

			if (cheat(AY_OBFUSCATE("Slide Walk & No Duck Delay")) == 2)
			{
				if (cheat(AY_OBFUSCATE("Slide Walk & No Duck Delay")).trigger == 0)
					SWshellcode = SpyInjectAndJump(SlideWalkFastCrouch, PVOID(createMove), 3); $$$;
				byte bytes[] = { 0x90, 0x90, 0x90, 0x90, 0x90 }; $$$;
				wvmb((DWORD)SWshellcode + 8, &bytes); $$$;
			}

			if (cheat(AY_OBFUSCATE("Slide Walk & No Duck Delay")) == 0)
			{
				byte bytes[] = { 0xFF,0x75,0x0C,0xF3,0x0F,0x10,0x45,0x08 }; $$$;
				wvmb(createMove, &bytes); $$$;
				VirtualFreeEx(hProcess, SWshellcode, 256, MEM_RELEASE); $$$;
			}
			cheat.Update(AY_OBFUSCATE("Slide Walk & No Duck Delay")); $$$;
		}

		if (cheat.Triggered(AY_OBFUSCATE("Grenade Trajectory")))
		{
			if (cheat(AY_OBFUSCATE("Grenade Trajectory")) == 1)
			{
				SetValue(AY_OBFUSCATE("cl_grenadepreview"), 1); $$$;
			}
			else
			{
				SetValue(AY_OBFUSCATE("cl_grenadepreview"), 0); $$$;
			}

			cheat.Update(AY_OBFUSCATE("Grenade Trajectory")); $$$;
		}

		if (cheat.Triggered(AY_OBFUSCATE("Crosshair Recoil & Spread")))
		{
			if (cheat(AY_OBFUSCATE("Crosshair Recoil & Spread")) != 0)
			{
				if (cheat(AY_OBFUSCATE("No Extra AimPunch")) == 2)
				{
					SetValue(AY_OBFUSCATE("cl_crosshair_recoil"), 2.0f); $$$;
				}
				else
				{
					SetValue(AY_OBFUSCATE("cl_crosshair_recoil"), 1.0f); $$$;
				}

				SetValue(AY_OBFUSCATE("weapon_debug_spread_show"), 1); $$$;
			}
			else
			{
				SetValue(AY_OBFUSCATE("cl_crosshair_recoil"), 0.0f); $$$;
				SetValue(AY_OBFUSCATE("weapon_debug_spread_show"), 0); $$$;
			}

			cheat.Update(AY_OBFUSCATE("Crosshair Recoil & Spread")); $$$;
		}

		if (cheat.Triggered(AY_OBFUSCATE("Enemy Details & Radarhack")))
		{
			if (cheat(AY_OBFUSCATE("Enemy Details & Radarhack")) == 1)
			{
				wvm<byte>(radarHax, 1); $$$;
				wvm<WORD>(seeEnemyInfo, 0x9090); $$$;
			}

			if (cheat(AY_OBFUSCATE("Enemy Details & Radarhack")) == 2)
			{
				wvm<byte>(radarHax, 1); $$$;
				wvm<WORD>(seeEnemyInfo, 0xC63B); $$$;
			}

			if (cheat(AY_OBFUSCATE("Enemy Details & Radarhack")) == 0)
			{
				wvm<byte>(radarHax, 0); $$$;
				wvm<WORD>(seeEnemyInfo, 0xC63B); $$$;
			}

			cheat.Update(AY_OBFUSCATE("Enemy Details & Radarhack")); $$$;

		}

		if (cheat.Triggered(AY_OBFUSCATE("Money; Rank Reveal")))
		{
			if (cheat(AY_OBFUSCATE("Money; Rank Reveal")) == 1)
			{
				revealOrig = rvm<DWORD>(reveal1); $$$;
				wvm<WORD>(reveal1, 0x9090); $$$;
				wvm<WORD>(reveal2, 0x9090); $$$;
			}

			if (cheat(AY_OBFUSCATE("Money; Rank Reveal")) == 2)
			{
				if (cheat(AY_OBFUSCATE("Money; Rank Reveal")).trigger == 0)
					revealOrig = rvm<DWORD>(reveal1); $$$;

				LPVOID shellCodeAddress, memeAddress; $$$;
				byte asm_stub[] =
				{
					0x68, 0x00, 0x00, 0x00, 0x00,   // push float* (1)
					0x55, 0x89, 0xE5,               // cdecl call frame
					0xB8, 0x00, 0x00, 0x00, 0x00,   // mov    eax,0x00000000 (9)
					0xFF, 0xD0,                     // call   eax
					0x83, 0xC4, 0x4,                // clear stack
					0x5D,                           // reset call frame
					0xC3                            // return
				}; $$$;

				D3DXVECTOR3 meme; $$$;
				meme.x = meme.y = meme.z = 0.f; $$$;
				static unsigned int shellSize = sizeof(asm_stub) + 1; $$$;
				unsigned int dataSize = (sizeof(LPVOID) + sizeof(DWORD)) + 2; $$$;
				shellCodeAddress = VirtualAllocEx(hProcess, NULL, shellSize + dataSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE); $$$;
				memeAddress = VirtualAllocEx(hProcess, NULL, sizeof(meme) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE); $$$;
				WriteProcessMemory(hProcess, memeAddress, &meme, sizeof(meme), NULL); $$$;
				WriteProcessMemory(hProcess, shellCodeAddress, &asm_stub, sizeof(asm_stub), NULL); $$$;
				WriteProcessMemory(hProcess, (LPVOID)((DWORD)shellCodeAddress + 0x1), &memeAddress, sizeof(LPVOID), NULL); $$$;
				wvm((DWORD)shellCodeAddress + 0x9, rankOffsetThing); $$$;
#ifdef DEBUG
				cout << AY_OBFUSCATE("RankReveal shellCodeAddress ") << (DWORD)shellCodeAddress << endl; $$$;
#endif
				HANDLE thread = CreateRemoteThread(hProcess, NULL, NULL, (LPTHREAD_START_ROUTINE)shellCodeAddress, NULL, NULL, NULL); $$$;
				WaitForSingleObject(thread, INFINITE); $$$;
				CloseHandle(thread); $$$;

				VirtualFreeEx(hProcess, shellCodeAddress, 256, MEM_RELEASE); $$$;
				VirtualFreeEx(hProcess, memeAddress, 256, MEM_RELEASE); $$$;
			}

			if (cheat(AY_OBFUSCATE("Money; Rank Reveal")) == 0)
			{
				wvm<DWORD>(reveal1, revealOrig); $$$;
				wvm<WORD>(reveal2, 0xC63B); $$$;
			}

			cheat.Update(AY_OBFUSCATE("Money; Rank Reveal")); $$$;
		}

		if (cheat.Triggered(AY_OBFUSCATE("No Extra AimPunch")))
		{

			if (cheat(AY_OBFUSCATE("No Extra AimPunch")) == 2)
			{
				byte shellCode1[] = { 0x90,0x90,0x90,0x90,punchExtraOrigBytes[4],punchExtraOrigBytes[5],punchExtraOrigBytes[6],punchExtraOrigBytes[7],
				punchExtraOrigBytes[8],punchExtraOrigBytes[9],punchExtraOrigBytes[10],punchExtraOrigBytes[11],punchExtraOrigBytes[12],punchExtraOrigBytes[13],
				punchExtraOrigBytes[14],punchExtraOrigBytes[4],punchExtraOrigBytes[4],0x90,0x90,0x90,0x90,0x90 }; $$$;
				wvmb(aimPunch, &shellCode1); $$$;
				SetValue(AY_OBFUSCATE("view_recoil_tracking"), 0.0f); $$$;

				if (cheat(AY_OBFUSCATE("Crosshair Recoil & Spread")) != 0)
					SetValue(AY_OBFUSCATE("cl_crosshair_recoil"), 2.0f); $$$;
			}

			if (cheat(AY_OBFUSCATE("No Extra AimPunch")) == 1)
			{
				byte shellCode1[] = { 0x90,0x90,0x90,0x90,punchExtraOrigBytes[4],punchExtraOrigBytes[5],punchExtraOrigBytes[6],punchExtraOrigBytes[7],
				punchExtraOrigBytes[8],punchExtraOrigBytes[9],punchExtraOrigBytes[10],punchExtraOrigBytes[11],punchExtraOrigBytes[12],punchExtraOrigBytes[13],
				punchExtraOrigBytes[14],punchExtraOrigBytes[4],punchExtraOrigBytes[4],0x90,0x90,0x90,0x90,0x90 }; $$$;
				wvmb(aimPunch, &shellCode1); $$$; 
				SetValue(AY_OBFUSCATE("view_recoil_tracking"), 0.45f); $$$;
				if (cheat(AY_OBFUSCATE("Crosshair Recoil & Spread")) != 0)
					SetValue(AY_OBFUSCATE("cl_crosshair_recoil"), 1.0f); $$$;
			}

			if (cheat(AY_OBFUSCATE("No Extra AimPunch")) == 0)
			{
				wvmb(aimPunch, &punchExtraOrigBytes); $$$;
				SetValue(AY_OBFUSCATE("view_recoil_tracking"), 0.45f); $$$;

				if (cheat(AY_OBFUSCATE("Crosshair Recoil & Spread")) != 0)
					SetValue(AY_OBFUSCATE("cl_crosshair_recoil"), 1.0f); $$$;
			}

			cheat.Update(AY_OBFUSCATE("No Extra AimPunch")); $$$;
		}

		if (cheat.Triggered(AY_OBFUSCATE("Thirdperson; Free Cam")))
		{
			if (cheat(AY_OBFUSCATE("Thirdperson; Free Cam")) != 0)
				wvm(localplayer + iObserverMode, 1); $$$;

			if (cheat(AY_OBFUSCATE("Thirdperson; Free Cam")) == 0)
				wvm(localplayer + iObserverMode, 0); $$$;

			cheat.Update(AY_OBFUSCATE("Thirdperson; Free Cam")); $$$;
		}

		if (cheat.Triggered(AY_OBFUSCATE("Player Glow & Color")))
		{
			if (cheat(AY_OBFUSCATE("Player Glow & Color")) == 0) {
				for (int i = 0; i < 64;  i++)
					wvm<DWORD>(rvm<DWORD>(client_dll + dwEntityList + i * 0x10) + 0x70, 0xFFFFFFFF); $$$;
			}
			cheat.Update(AY_OBFUSCATE("Player Glow & Color")); $$$;
		}

		if (cheat.Triggered(AY_OBFUSCATE("No Hands & Scope & Postproc")))
		{
			if (cheat(AY_OBFUSCATE("No Hands & Scope & Postproc")) != 0)
			{
				SetValue(AY_OBFUSCATE("mat_postprocess_enable"), 0); $$$;
			}
			else { SetValue(AY_OBFUSCATE("mat_postprocess_enable"), 1); $$$; }
			cheat.Update(AY_OBFUSCATE("No Hands & Scope & Postproc")); $$$;
		}

		if (rvm<DWORD>(clientstate + dwClientState_State) == 6) {
			if (cheat(AY_OBFUSCATE("No Hands & Scope & Postproc")) == 1)
			{
				wvm<BYTE>(localplayer + nModelIndex, 0); $$$; //arms
				wvm<BYTE>(localplayer + bIsScoped, 0); $$$;
			}

			if (cheat(AY_OBFUSCATE("Reduce Flash & Smoke")) != 0)
			{
				wvm<float>(localplayer + flFlashMaxAlpha, 50.0f); $$$;
				wvm<int>(noSmoke, 0); $$$;
			}

			if (cheat(AY_OBFUSCATE("Thirdperson; Free Cam")) != 0) {
				if (!rvm<DWORD>(localplayer + iObserverMode))
					wvm(localplayer + iObserverMode, 1); $$$;
			}

			if (cheat(AY_OBFUSCATE("Hit Sound")) != 0)
			{
				totalhits = rvm<int>(localplayer + totalHitsOnServer); $$$;
				if (totalhits > hits)
				{
					hits = totalhits; $$$;
					sndPlaySound((LPCSTR)lpRes, SND_MEMORY | SND_ASYNC); $$$;
				}
				if (totalhits == 0) hits = 0; $$$;
			}

			if (cheat(AY_OBFUSCATE("Zoom; Field of View")) == 2)
			{
				if (rvm<DWORD>(localplayer + defaultFOV) != 120)
					wvm(localplayer + defaultFOV, 120); $$$;
			}
		}
		Sleep(1); $$$;
	}
}

void FreeCam() {
	DWORD unBlockMoving = rvm<DWORD>(client_dll + blockMoving); $$$;
	wvm(client_dll + blockMoving, 0x5E909090); $$$;

	__int64 freeCamOrig1 = rvm<__int64>(client_dll + freeCam); $$$;

	LPVOID Addr = VirtualAllocEx(
		hProcess,
		0,
		sizeof(DWORD),
		MEM_COMMIT | MEM_RESERVE,
		PAGE_EXECUTE_READWRITE
	); $$$;

	dword2bytes addr = { (DWORD)Addr }; $$$;
	byte shellcode[] = { 0x89, 0x3D, addr.bytes[0], addr.bytes[1], addr.bytes[2], addr.bytes[3], 0xEB, 0x0C }; $$$;

	wvmb(client_dll + freeCam, &shellcode); $$$;
	wvm(client_dll + freeCam + 0xC9, 0x909022EB); $$$;

	float flyangX, flyangY; $$$;

	Sleep(100); $$$;
	DWORD visualOrigin = rvm<DWORD>(DWORD(Addr)); $$$;
	D3DXVECTOR3 vispos = rvm<D3DXVECTOR3>(visualOrigin); $$$;
#ifdef DEBUG
	cout << AY_OBFUSCATE("Free Cam activated, visual position address = 0x") << hex << visualOrigin << "\n"; $$$;
#endif

	while (cheat(AY_OBFUSCATE("Thirdperson; Free Cam")) == 2)  
	{
		flyangX = rvm<float>(clientstate + dwClientState_ViewAngles); $$$;
		flyangY = rvm<float>(clientstate + dwClientState_ViewAngles + 4); $$$;

		flyangY -= 90.0; $$$;
		if (GetAsyncKeyState(0x57) < 0) //W
		{
			vispos[0] += -sin(flyangY * PI / 180); $$$;
			vispos[1] += cos(flyangY * PI / 180); $$$;
			vispos[2] += -sin(flyangX * PI / 180); $$$;
			wvm(visualOrigin, vispos); $$$;
		}

		if (GetAsyncKeyState(0x53) < 0) //S
		{
			vispos[0] -= -sin(flyangY * PI / 180); $$$;
			vispos[1] -= cos(flyangY * PI / 180); $$$;
			vispos[2] += sin(flyangX * PI / 180); $$$;
			wvm(visualOrigin, vispos); $$$;
		}

		if (GetAsyncKeyState(0x41) < 0) //A
		{
			vispos[0] -= cos(flyangY * PI / 180); $$$;
			vispos[1] -= sin(flyangY * PI / 180); $$$;
			wvm(visualOrigin, vispos); $$$;
		}

		if (GetAsyncKeyState(0x44) < 0) //D
		{
			vispos[0] += cos(flyangY * PI / 180); $$$;
			vispos[1] += sin(flyangY * PI / 180); $$$;
			wvm(visualOrigin, vispos); $$$;
		}
		Sleep(1); $$$;
	}

	wvm<__int64>(client_dll + freeCam, freeCamOrig1); $$$;
	wvm(client_dll + freeCam + 0xC9, 0x07110FF3); $$$;
	wvm(client_dll + blockMoving, unBlockMoving); $$$;
	VirtualFreeEx(hProcess, Addr, sizeof(DWORD), MEM_RELEASE); $$$;
}


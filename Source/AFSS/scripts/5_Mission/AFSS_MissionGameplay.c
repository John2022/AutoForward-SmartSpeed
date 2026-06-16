modded class MissionGameplay
{
	protected bool m_AFSS_AutoForwardState;
	protected int m_AFSS_AutoForwardSpeed;
	protected int m_AFSS_LastManualSpeed;

	protected bool m_AFSS_WalkToggleState;
	protected float m_AFSS_Time;
	protected float m_AFSS_LastWalkTempPressTime;

	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		m_AFSS_Time = m_AFSS_Time + timeslice;

		if (GetGame().GetUIManager().GetMenu() != NULL)
		{
			return;
		}

		Input input = GetGame().GetInput();
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

		if (!input || !player)
		{
			return;
		}

		if (!m_AFSS_AutoForwardState)
		{
			AFSS_UpdateWalkToggleState(input);
			AFSS_UpdateLastManualSpeed(input);
		}

		if (input.LocalPress("UAAFSSAutoForward"))
		{
			if (m_AFSS_AutoForwardState)
			{
				AFSS_StopAutoForward(player);
			}
			else
			{
				m_AFSS_AutoForwardSpeed = AFSS_DetectInitialSpeed(input);
				m_AFSS_AutoForwardState = true;
				AFSS_UpdateMovement(player, m_AFSS_AutoForwardSpeed, 1);
			}

			return;
		}

		if (m_AFSS_AutoForwardState)
		{
			if (input.LocalPress("UATurbo"))
			{
				m_AFSS_WalkToggleState = false;
				m_AFSS_AutoForwardSpeed = m_AFSS_AutoForwardSpeed + 1;

				if (m_AFSS_AutoForwardSpeed > 3)
				{
					m_AFSS_AutoForwardSpeed = 3;
				}

				AFSS_UpdateMovement(player, m_AFSS_AutoForwardSpeed, 1);
				return;
			}

			if (input.LocalPress("UAWalkRunTemp"))
			{
				m_AFSS_AutoForwardSpeed = m_AFSS_AutoForwardSpeed - 1;

				if (m_AFSS_AutoForwardSpeed < 1)
				{
					m_AFSS_AutoForwardSpeed = 1;
				}

				AFSS_UpdateMovement(player, m_AFSS_AutoForwardSpeed, 1);
				return;
			}

			if (input.LocalPress("UAMoveForward") || input.LocalPress("UAMoveBack") || input.LocalPress("UAMoveLeft") || input.LocalPress("UAMoveRight") || input.LocalPress("UAGetOver"))
			{
				AFSS_StopAutoForward(player);
				return;
			}
		}
	}

	protected void AFSS_UpdateWalkToggleState(Input input)
	{
		if (input.LocalPress("UATurbo"))
		{
			m_AFSS_WalkToggleState = false;
			m_AFSS_LastManualSpeed = 3;
			m_AFSS_LastWalkTempPressTime = 0;
			return;
		}

		if (input.LocalPress("UAWalkRunTemp"))
		{
			if (m_AFSS_LastWalkTempPressTime > 0 && m_AFSS_Time - m_AFSS_LastWalkTempPressTime <= 0.45)
			{
				m_AFSS_WalkToggleState = !m_AFSS_WalkToggleState;

				if (m_AFSS_WalkToggleState)
				{
					m_AFSS_LastManualSpeed = 1;
				}
				else
				{
					m_AFSS_LastManualSpeed = 2;
				}

				m_AFSS_LastWalkTempPressTime = 0;
			}
			else
			{
				m_AFSS_LastWalkTempPressTime = m_AFSS_Time;
			}
		}
	}

	protected void AFSS_UpdateLastManualSpeed(Input input)
	{
		if (input.LocalValue("UATurbo") > 0)
		{
			m_AFSS_WalkToggleState = false;
			m_AFSS_LastManualSpeed = 3;
			return;
		}

		if (m_AFSS_WalkToggleState)
		{
			m_AFSS_LastManualSpeed = 1;
			return;
		}

		if (input.LocalValue("UAWalkRunTemp") > 0 || input.LocalValue("UAWalkRunForced") > 0)
		{
			m_AFSS_LastManualSpeed = 1;
			return;
		}

		if (input.LocalValue("UAMoveForward") > 0 || input.LocalValue("UAMoveBack") > 0 || input.LocalValue("UAMoveLeft") > 0 || input.LocalValue("UAMoveRight") > 0)
		{
			m_AFSS_LastManualSpeed = 2;
			return;
		}

		m_AFSS_LastManualSpeed = 0;
	}

	protected int AFSS_DetectInitialSpeed(Input input)
	{
		if (input.LocalValue("UATurbo") > 0)
		{
			m_AFSS_WalkToggleState = false;
			return 3;
		}

		if (m_AFSS_WalkToggleState)
		{
			return 1;
		}

		if (input.LocalValue("UAWalkRunTemp") > 0 || input.LocalValue("UAWalkRunForced") > 0)
		{
			return 1;
		}

		if (m_AFSS_LastManualSpeed > 0)
		{
			return m_AFSS_LastManualSpeed;
		}

		return 2;
	}

	protected void AFSS_StopAutoForward(PlayerBase player)
	{
		m_AFSS_AutoForwardState = false;
		m_AFSS_AutoForwardSpeed = 0;
		AFSS_UpdateMovement(player, 0, 0);
	}

	protected void AFSS_UpdateMovement(PlayerBase player, int speed, int angle)
	{
		player.GetInputController().OverrideMovementSpeed(m_AFSS_AutoForwardState, speed);
		player.GetInputController().OverrideMovementAngle(m_AFSS_AutoForwardState, angle);

		if (GetGame().IsMultiplayer())
		{
			auto params = new Param3<bool, int, int>(m_AFSS_AutoForwardState, speed, angle);
			GetGame().RPCSingleParam(player, -77777, params, true);
		}
	}
}

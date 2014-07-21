package com.ankamagames.wakfu.client.binaryStorage;

public class AchievementBinaryData implements dEZ {
    protected int az;
    protected int exW;
    protected boolean bN;
    protected boolean msO;
    protected boolean daH;
    protected String Uz;
    protected dFo[] nbj;
    protected dAf[] nbk;
    protected int aSf;
    protected int mZK;
    protected boolean msQ;
    protected boolean msR;
    protected boolean msS;
    protected int msY;
    protected int msZ;
    protected boolean msT;
    protected int msV;
    protected long nbl;
    protected long nbm;
    protected boolean msU;
    protected int aZE;
    
    public AchievementBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public int aZb()
    {
        return this.exW;
    }
    
    public boolean isVisible()
    {
        return this.bN;
    }
    
    public boolean dtY()
    {
        return this.msO;
    }
    
    public boolean isActive()
    {
        return this.daH;
    }
    
    public String gW()
    {
        return this.Uz;
    }
    
    public dFo[] dJr()
    {
        return this.nbj;
    }
    
    public dAf[] dJs()
    {
        return this.nbk;
    }
    
    public int getDuration()
    {
        return this.aSf;
    }
    
    public int dIB()
    {
        return this.mZK;
    }
    
    public boolean dua()
    {
        return this.msQ;
    }
    
    public boolean buF()
    {
        return this.msR;
    }
    
    public boolean dub()
    {
        return this.msS;
    }
    
    public int duc()
    {
        return this.msY;
    }
    
    public int dud()
    {
        return this.msZ;
    }
    
    public boolean dtZ()
    {
        return this.msT;
    }
    
    public int due()
    {
        return this.msV;
    }
    
    public long dJt()
    {
        return this.nbl;
    }
    
    public long dJu()
    {
        return this.nbm;
    }
    
    public boolean duf()
    {
        return this.msU;
    }
    
    public int oM()
    {
        return this.aZE;
    }
    
    public void reset()
    {
        this.az = 0;
        this.exW = 0;
        this.bN = false;
        this.msO = false;
        this.daH = false;
        this.Uz = null;
        this.nbj = null;
        this.nbk = null;
        this.aSf = 0;
        this.mZK = 0;
        this.msQ = false;
        this.msR = false;
        this.msS = false;
        this.msY = 0;
        this.msZ = 0;
        this.msT = false;
        this.msV = 0;
        this.nbl = 0L;
        this.nbm = 0L;
        this.msU = false;
        this.aZE = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        this.exW = a.getInt();
        this.bN = a.readBoolean();
        this.msO = a.readBoolean();
        this.daH = a.readBoolean();
        this.Uz = a.clg().intern();
        int i = a.getInt();
        this.nbj = new dFo[i];
        int i0 = 0;
        while(i0 < i)
        {
            this.nbj[i0] = new dFo();
            this.nbj[i0].a(a);
            i0 = i0 + 1;
        }
        int i1 = a.getInt();
        this.nbk = new dAf[i1];
        int i2 = 0;
        while(i2 < i1)
        {
            this.nbk[i2] = new dAf();
            this.nbk[i2].a(a);
            i2 = i2 + 1;
        }
        this.aSf = a.getInt();
        this.mZK = a.getInt();
        this.msQ = a.readBoolean();
        this.msR = a.readBoolean();
        this.msS = a.readBoolean();
        this.msY = a.getInt();
        this.msZ = a.getInt();
        this.msT = a.readBoolean();
        this.msV = a.getInt();
        this.nbl = a.getLong();
        this.nbm = a.getLong();
        this.msU = a.readBoolean();
        this.aZE = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eDq.getId();
    }
}
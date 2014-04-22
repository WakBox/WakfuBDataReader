package com.ankamagames.wakfu.client.binaryStorage;

public class StaticEffectBinaryData implements dEZ {
    protected int biz;
    protected int aZo;
    protected int biA;
    protected short biB;
    protected int[] biC;
    protected short biD;
    protected short biE;
    protected int[] biF;
    protected short biG;
    protected int[] biH;
    protected int[] biI;
    protected int[] biJ;
    protected int[] biK;
    protected int[] biL;
    protected int[] biM;
    protected int[] biN;
    protected String biO;
    protected long[] biP;
    protected boolean biQ;
    protected int biR;
    protected float biS;
    protected boolean aVU;
    protected boolean aVT;
    protected short biT;
    protected float biU;
    protected float[] biV;
    protected float biW;
    protected float biX;
    protected byte biY;
    protected byte biZ;
    protected byte bja;
    protected boolean bjb;
    protected short bjc;
    protected float bjd;
    protected byte bje;
    protected boolean bjf;
    protected String bjg;
    protected short bjh;
    protected short bji;
    protected String bjj;
    protected String bjk;
    protected String bjl;
    protected boolean bjm;
    protected boolean bjn;
    protected boolean bjo;
    protected boolean bjp;
    protected boolean bjq;
    protected boolean bjr;
    protected int bjs;
    protected boolean bjt;
    protected int[] bju;
    protected boolean bjv;
    protected boolean bjw;
    protected boolean bjx;
    protected boolean bjy;
    protected boolean bjz;
    
    public StaticEffectBinaryData()
    {
        super();
    }
    
    public boolean Ay()
    {
        return false;
    }
    
    public boolean Az()
    {
        return false;
    }
    
    public boolean AA()
    {
        return false;
    }
    
    public boolean AB()
    {
        String s = this.Bs().trim();
        boolean b = this.Bm();
        if(this.AC())
        {
            return false;
        }
        else if(s.startsWith("ITEM"))
        {
            boolean b0 = false;
            label5: {
                label6: {
                    label7: {
                        if(!b)
                        {
                            break label7;
                        }
                        if(this.AD())
                        {
                            break label6;
                        }
                    }
                    b0 = false;
                    break label5;
                }
                b0 = true;
            }
            return b0;
        }
        else
        {
            boolean b1 = false;
            String s0 = this.Br().trim();
            boolean b2 = s0.startsWith("SPELL");
            label0: {
                label1: {
                    label2: {
                        label4: {
                            if(!b2)
                            {
                                break label4;
                            }
                            if(b)
                            {
                                break label2;
                            }
                        }
                        if(s0.startsWith("GROUP"))
                        {
                            break label2;
                        }
                        if(s0.startsWith("BOMB"))
                        {
                            break label2;
                        }
                        if(s0.startsWith("AREA"))
                        {
                            break label2;
                        }
                        if(s0.startsWith("IEP_DESTRUCTIBLE"))
                        {
                            break label2;
                        }
                        boolean b3 = s0.startsWith("STATE");
                        label3: {
                            if(!b3)
                            {
                                break label3;
                            }
                            if(b)
                            {
                                break label2;
                            }
                        }
                        if(!s0.startsWith("TIMELINE"))
                        {
                            break label1;
                        }
                        if(!b)
                        {
                            break label1;
                        }
                    }
                    b1 = true;
                    break label0;
                }
                b1 = false;
            }
            return b1;
        }
    }
    
    public boolean AC()
    {
        if(this.bju != null)
        {
            int i = 0;
            while(i < this.bju.length)
            {
                if(Sq.gP(this.bju[i]) != Sq.czz)
                {
                    i = i + 1;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            return false;
        }
    }
    
    public boolean AD()
    {
        String s = this.Bs().trim();
        if(this.AC())
        {
            return false;
        }
        else if(s.startsWith("ITEM"))
        {
            return s.endsWith("_USE");
        }
        else
        {
            boolean b = false;
            boolean b0 = this.Bm();
            String s0 = this.Br().trim();
            boolean b1 = s0.startsWith("SET");
            label0: {
                label1: {
                    label2: {
                        if(b1)
                        {
                            break label2;
                        }
                        boolean b2 = s0.startsWith("SPELL");
                        label3: {
                            if(!b2)
                            {
                                break label3;
                            }
                            if(!b0)
                            {
                                break label2;
                            }
                        }
                        if(s0.startsWith("PROTECTOR"))
                        {
                            break label2;
                        }
                        if(s0.startsWith("BUILDING"))
                        {
                            break label2;
                        }
                        if(!s0.startsWith("APTITUDE"))
                        {
                            break label1;
                        }
                    }
                    b = false;
                    break label0;
                }
                b = true;
            }
            return b;
        }
    }
    
    public int AE()
    {
        return this.biz;
    }
    
    public int eG()
    {
        return this.aZo;
    }
    
    public int AF()
    {
        return this.biA;
    }
    
    public short AG()
    {
        int i = this.biB;
        return (short)i;
    }
    
    public int[] AH()
    {
        return this.biC;
    }
    
    public short AI()
    {
        int i = this.biD;
        return (short)i;
    }
    
    public short AJ()
    {
        int i = this.biE;
        return (short)i;
    }
    
    public int[] AK()
    {
        return this.biF;
    }
    
    public short AL()
    {
        int i = this.biG;
        return (short)i;
    }
    
    public int[] AM()
    {
        return this.biH;
    }
    
    public int[] AN()
    {
        return this.biI;
    }
    
    public int[] AO()
    {
        return this.biJ;
    }
    
    public int[] AP()
    {
        return this.biK;
    }
    
    public int[] AQ()
    {
        return this.biL;
    }
    
    public int[] AR()
    {
        return this.biM;
    }
    
    public int[] AS()
    {
        return this.biN;
    }
    
    public String AT()
    {
        return this.biO;
    }
    
    public long[] AU()
    {
        return this.biP;
    }
    
    public boolean AV()
    {
        return this.biQ;
    }
    
    public int AW()
    {
        return this.biR;
    }
    
    public float AX()
    {
        return this.biS;
    }
    
    public boolean AY()
    {
        return this.aVU;
    }
    
    public boolean AZ()
    {
        return this.aVT;
    }
    
    public short Ba()
    {
        int i = this.biT;
        return (short)i;
    }
    
    public float Bb()
    {
        return this.biU;
    }
    
    public float[] Bc()
    {
        return this.biV;
    }
    
    public float Bd()
    {
        return this.biW;
    }
    
    public float Be()
    {
        return this.biX;
    }
    
    public byte Bf()
    {
        int i = this.biY;
        return (byte)i;
    }
    
    public byte Bg()
    {
        int i = this.biZ;
        return (byte)i;
    }
    
    public byte Bh()
    {
        int i = this.bja;
        return (byte)i;
    }
    
    public boolean Bi()
    {
        return this.bjb;
    }
    
    public short Bj()
    {
        int i = this.bjc;
        return (short)i;
    }
    
    public float Bk()
    {
        return this.bjd;
    }
    
    public byte Bl()
    {
        int i = this.bje;
        return (byte)i;
    }
    
    public boolean Bm()
    {
        return this.bjf;
    }
    
    public String Bn()
    {
        return this.bjg;
    }
    
    public short Bo()
    {
        int i = this.bjh;
        return (short)i;
    }
    
    public short Bp()
    {
        int i = this.bji;
        return (short)i;
    }
    
    public String Bq()
    {
        return this.bjj;
    }
    
    public String Br()
    {
        return this.bjk;
    }
    
    public String Bs()
    {
        return this.bjl;
    }
    
    public boolean Bt()
    {
        return this.bjm;
    }
    
    public boolean Bu()
    {
        return this.bjn;
    }
    
    public boolean Bv()
    {
        return this.bjo;
    }
    
    public boolean Bw()
    {
        return this.bjp;
    }
    
    public boolean Bx()
    {
        return this.bjq;
    }
    
    public boolean By()
    {
        return this.bjr;
    }
    
    public int Bz()
    {
        return this.bjs;
    }
    
    public boolean BA()
    {
        return this.bjt;
    }
    
    public int[] BB()
    {
        return this.bju;
    }
    
    public boolean BC()
    {
        return this.bjv;
    }
    
    public boolean BD()
    {
        return this.bjw;
    }
    
    public boolean BE()
    {
        return this.bjx;
    }
    
    public boolean BF()
    {
        return this.bjy;
    }
    
    public boolean BG()
    {
        return this.bjz;
    }
    
    public void reset()
    {
        this.biz = 0;
        this.aZo = 0;
        this.biA = 0;
        this.biB = (short)0;
        this.biC = null;
        this.biD = (short)0;
        this.biE = (short)0;
        this.biF = null;
        this.biG = (short)0;
        this.biH = null;
        this.biI = null;
        this.biJ = null;
        this.biK = null;
        this.biL = null;
        this.biM = null;
        this.biN = null;
        this.biO = null;
        this.biP = null;
        this.biQ = false;
        this.biR = 0;
        this.biS = 0.0f;
        this.aVU = false;
        this.aVT = false;
        this.biT = (short)0;
        this.biU = 0.0f;
        this.biV = null;
        this.biW = 0.0f;
        this.biX = 0.0f;
        this.biY = (byte)0;
        this.biZ = (byte)0;
        this.bja = (byte)0;
        this.bjb = false;
        this.bjc = (short)0;
        this.bjd = 0.0f;
        this.bje = (byte)0;
        this.bjf = false;
        this.bjg = null;
        this.bjh = (short)0;
        this.bji = (short)0;
        this.bjj = null;
        this.bjk = null;
        this.bjl = null;
        this.bjm = false;
        this.bjn = false;
        this.bjo = false;
        this.bjp = false;
        this.bjq = false;
        this.bjr = false;
        this.bjs = 0;
        this.bjt = false;
        this.bju = null;
        this.bjv = false;
        this.bjw = false;
        this.bjx = false;
        this.bjy = false;
        this.bjz = false;
    }
    
    public void a(ceb a)
    {
        this.biz = a.getInt();
        this.aZo = a.getInt();
        this.biA = a.getInt();
        int i = a.getShort();
        this.biB = (short)i;
        this.biC = a.cli();
        int i0 = a.getShort();
        this.biD = (short)i0;
        int i1 = a.getShort();
        this.biE = (short)i1;
        this.biF = a.cli();
        int i2 = a.getShort();
        this.biG = (short)i2;
        this.biH = a.cli();
        this.biI = a.cli();
        this.biJ = a.cli();
        this.biK = a.cli();
        this.biL = a.cli();
        this.biM = a.cli();
        this.biN = a.cli();
        this.biO = a.clg().intern();
        this.biP = a.clm();
        this.biQ = a.readBoolean();
        this.biR = a.getInt();
        this.biS = a.getFloat();
        this.aVU = a.readBoolean();
        this.aVT = a.readBoolean();
        int i3 = a.getShort();
        this.biT = (short)i3;
        this.biU = a.getFloat();
        this.biV = a.clk();
        this.biW = a.getFloat();
        this.biX = a.getFloat();
        int i4 = a.get();
        this.biY = (byte)i4;
        int i5 = a.get();
        this.biZ = (byte)i5;
        int i6 = a.get();
        this.bja = (byte)i6;
        this.bjb = a.readBoolean();
        int i7 = a.getShort();
        this.bjc = (short)i7;
        this.bjd = a.getFloat();
        int i8 = a.get();
        this.bje = (byte)i8;
        this.bjf = a.readBoolean();
        this.bjg = a.clg().intern();
        int i9 = a.getShort();
        this.bjh = (short)i9;
        int i10 = a.getShort();
        this.bji = (short)i10;
        this.bjj = a.clg().intern();
        this.bjk = a.clg().intern();
        this.bjl = a.clg().intern();
        this.bjm = a.readBoolean();
        this.bjn = a.readBoolean();
        this.bjo = a.readBoolean();
        this.bjp = a.readBoolean();
        this.bjq = a.readBoolean();
        this.bjr = a.readBoolean();
        this.bjs = a.getInt();
        this.bjt = a.readBoolean();
        this.bju = a.cli();
        this.bjv = a.readBoolean();
        this.bjw = a.readBoolean();
        this.bjx = a.readBoolean();
        this.bjy = a.readBoolean();
        this.bjz = a.readBoolean();
    }
    
    final public int gZ()
    {
        return aPw.eEF.getId();
    }
}